import openai
import os
import re
import torch
from transformers import AutoModelForCausalLM, AutoTokenizer
from Config import Config
from abc import ABC, abstractmethod # 导入 ABC 和 abstractmethod 用于创建抽象基类


os.environ['HF_ENDPOINT'] = 'https://hf-mirror.com'


# 抽象基类，定义了统一的接口
class BaseChatModel(ABC):
    def __init__(self, config: Config):
        self.config = config
        # 历史消息，用于维护对话上下文
        self.messages = [{"role": "system", "content": "You are a helpful assistant."}]

    @abstractmethod
    def generate_response(self, user_input: str) -> str:
        """
        根据用户输入生成响应。
        子类必须实现此方法。
        """
        pass

    def _process_response_think_tags(self, response_text: str) -> str:
        """
        根据配置处理响应中的 <think> 标签。
        """
        if not self.config.think_mode_enabled:
            # 如果 think_mode_enabled 为 False，则移除 <think>...</think> 部分
            return re.sub(r'<think>.*?</think>', '', response_text, flags=re.DOTALL)
        return response_text


# 使用 OpenAI 兼容 API 的 LLM 类
class OpenAILLM(BaseChatModel):
    def __init__(self, config: Config):
        super().__init__(config)
        self.client = openai.OpenAI(
            base_url=self.config.base_url,
            api_key=self.config.api_key
        )
        # 为 OpenAI API 使用其特定的模型名称和温度
        self.model_name = self.config.api_model
        self.temperature = self.config.api_temperature
        self.top_p =self.config.api_top_p


    def generate_response(self, user_input: str) -> str:
        try:
            # 添加用户输入到消息历史
            self.messages.append({"role": "user", "content": user_input})

            # 调用 OpenAI API
            response = self.client.chat.completions.create(
                model=self.model_name,
                messages=self.messages,
                temperature=self.temperature,
                top_p = self.top_p
            )

            assistant_response = response.choices[0].message.content

            # 处理 <think> 标签，并更新历史
            processed_response = self._process_response_think_tags(assistant_response)
            self.messages.append({"role": "assistant", "content": assistant_response}) # 原始响应加入历史以保持完整上下文

            return processed_response

        except Exception as e:
            print(f"OpenAI API 调用失败: {e}")
            # 从历史中移除失败的用户输入，避免下次重复发送
            if self.messages and self.messages[-1]["role"] == "user":
                self.messages.pop()
            return f"生成响应失败: {e}"


# 使用 Hugging Face Transformers 加载本地模型的 LLM 类
class HuggingFaceLLM(BaseChatModel):
    def __init__(self, config: Config):
        super().__init__(config)

        # 确定设备：如果有 CUDA 就用 CUDA，否则用 CPU
        self.device = "cuda" if torch.cuda.is_available() else "cpu"
        print(f"Using device: {self.device}")


       
        self.model_name = config.local_model_name
        self.model = None
        self.tokenizer =None
        self.fine_tuned_adapter = self.config.fine_tuned_adapter

         # 为本地模型使用其特定的名称和温度（如果适用）
        self.temperature = self.config.local_temperature
        self.top_p =self.config.local_top_p

        self.history = [] 

        if not config.fine_tune:
            print(f"正在加载本地模型: {self.model_name}")
            self.tokenizer = AutoTokenizer.from_pretrained(self.model_name)
            self.model = AutoModelForCausalLM.from_pretrained(self.model_name).to(self.device)
            print("本地模型加载完成。")
        else:
            print(f"正在加载微调模型: {self.model_name} {self.fine_tuned_adapter}")
            self.model, self.tokenizer = self.load_fine_tuned_model(
                model_name=self.model_name,
                peft_model_path=self.fine_tuned_adapter,
            )
            # 确保微调模型也移动到指定设备
            self.model = self.model.to(self.device)
            print("微调模型加载完成。")
    
    @classmethod
    def load_fine_tuned_model(cls, model_name: str, peft_model_path: str, device: str = None):
        """
        类方法：加载带有 LoRA 适配器的微调模型。

        Args:
            model_name (str): 原始基础模型的名称或路径。
            peft_model_path (str): 保存 LoRA 适配器的路径。
            device (str, optional): 加载模型到的设备（"cuda" 或 "cpu"）。默认为自动检测。

        Returns:
            peft.PeftModel: 加载并应用了 LoRA 适配器的模型。
            transformers.AutoTokenizer: 对应的分词器。
        """


        if device is None:
            device = "cuda" if torch.cuda.is_available() else "cpu"

        print(f"正在加载基础模型: {model_name}")
        base_model = AutoModelForCausalLM.from_pretrained(model_name).to(device)
        base_tokenizer = AutoTokenizer.from_pretrained(model_name)

        print(f"正在加载 PEFT 适配器: {peft_model_path}")
        fine_tuned_model = PeftModel.from_pretrained(base_model, peft_model_path)
        print("模型加载并应用 LoRA 适配器完成。")

        return fine_tuned_model, base_tokenizer

    
    def generate_response(self, user_input: str) -> str:
        try:
           
            messages = self.history + [{"role": "user", "content": user_input}]

            text = self.tokenizer.apply_chat_template(
                messages,
                tokenize=False,
                add_generation_prompt=True
            )

            # 将输入张量移动到与模型相同的设备
            inputs = self.tokenizer(text, return_tensors="pt").to(self.device)
           
            response_ids = self.model.generate(**inputs, 
            max_new_tokens=32768,
            temperature=self.temperature,
            top_p=self.top_p
            )[0][len(inputs.input_ids[0]):].tolist()
            assistant_response = self.tokenizer.decode(response_ids, skip_special_tokens=True)


            self.history.append({"role": "user", "content": user_input})
            self.history.append({"role": "assistant", "content": assistant_response})

            # 处理 <think> 标签，并更新历史
            processed_response = self._process_response_think_tags(assistant_response)

            return processed_response

        except Exception as e:
            print(f"本地模型生成响应失败: {e}")
            # 从历史中移除失败的用户输入
            if self.messages and self.messages[-1]["role"] == "user":
                self.messages.pop()
            return f"生成响应失败: {e}"


# 主控制类，根据配置选择使用哪种 LLM 实现
class Chatbot:
    def __init__(self, config: Config):
        self.config = config
        if self.config.use_api_model:
            print("正在初始化 API 模式的 LLM...")
            self.llm_instance = OpenAILLM(config)
            print(f"初始化完成，使用模型 {config.api_model}")
        else:
            print("正在初始化本地模式的 LLM...")
            self.llm_instance = HuggingFaceLLM(config)
            print(f"初始化完成，使用模型 {config.local_model_name}")

    def chat(self, user_input: str) -> str:
        response = self.llm_instance.generate_response(user_input)
        return response
    



# 示例用法
if __name__ == "__main__":
    # --- 示例 1: 使用 API 模型 ---
    print("--- 示例 1: 使用 API 模型 ---")
    api_config = Config()
    api_config.use_api_model = True 
    api_bot = Chatbot(api_config)

    user_input_api_1 = "你好，你是一个什么样的助手？"
    print(f"User: {user_input_api_1}")
    response_api_1 = api_bot.chat(user_input_api_1)
    print(f"Bot: {response_api_1}")
    print("----------------------")

    user_input_api_2 = "请问草莓(strawberries)里有多少个字母 'r'？"
    print(f"User: {user_input_api_2}")
    response_api_2 = api_bot.chat(user_input_api_2)
    print(f"Bot: {response_api_2}")
    print("----------------------")


    # --- 示例 2: 使用本地 Hugging Face 模型 ---
    print("\n--- 示例 2: 使用本地 Hugging Face 模型 ---")
    local_config = Config()
    local_config.use_api_model = False 

    local_bot = Chatbot(local_config)

    user_input_local_1 = "你好，请问你是谁？"
    print(f"User: {user_input_local_1}")
    response_local_1 = local_bot.chat(user_input_local_1)
    print(f"Bot: {response_local_1}")
    print("----------------------")

    user_input_local_2 = "请问蓝莓(blueberries)里有多少个字母 'r'？"
    print(f"User: {user_input_local_2}")
    response_local_2 = local_bot.chat(user_input_local_2)
    print(f"Bot: {response_local_2}")
    print("----------------------")

    user_input_local_3 = "那么苹果(apples)里有多少个字母 'p'？"
    print(f"User: {user_input_local_3}")
    response_local_3 = local_bot.chat(user_input_local_3)
    print(f"Bot: {response_local_3}")
    print("----------------------")
