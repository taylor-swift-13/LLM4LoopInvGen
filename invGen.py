import openai
import argparse
import re



class InvGenerator:
    def __init__(self):

        self.llm = 'gpt-4o'
        # OpenAI 客户端初始化
        self.client = openai.OpenAI(
            base_url="https://yunwu.ai/v1",
            api_key="sk-S3fNVvxTTDcQymGTYJU35ZheQZ6cON1zZW0rMGeM8F1nIA6l"
        )
        # 初始化消息列表
        self.messages = [
            {"role": "system", "content": "You are a helpful assistant."}
        ]

    def parse_args(self):
        """设置命令行参数解析器"""
        parser = argparse.ArgumentParser(description="Run Frama-C WP on a C file.")
        parser.add_argument('file_name', help="Path to the C file to analyze")
        return parser.parse_args()
    
    def get_prompt(self,c_code):
          # 从文件中读取 prompt 模板
        with open("prompt/prompt_1.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # 替换模板中的 {code} 占位符
        prompt = prompt_template.format(code=c_code)

        return prompt

    def get_user_prompt(self, c_file_path):
        """从 C 文件中读取内容并生成用户提示"""
        try:
            with open(c_file_path, 'r') as file:
                c_code = file.read()
        except Exception as e:
            print(f"Error reading file {c_file_path}: {e}")
            return None

        user_input = self.get_prompt(c_code)

        return user_input

    def get_annotations(self, user_prompt):
        """调用 OpenAI API 获取 ACSL 注释"""
        # 将内容添加到消息中
        self.messages.append({"role": "user", "content": user_prompt})

        # 获取助手的响应
        response = self.client.chat.completions.create(
            model=self.llm,
            messages=self.messages,
            temperature=0.7
        )

        def extract_last_c_code(text):
                # 匹配 C 代码块（Markdown 代码块 或 以 #include 开头的代码）
                code_blocks = re.findall(r'```c(.*?)```', text, re.DOTALL)  # Markdown 代码块

                return code_blocks[-1] if code_blocks else text  # 返回最后一个 C 代码块

            # 处理响应
        assistant_response = response.choices[0].message.content
        print(assistant_response)
        assistant_response = re.sub(r'>\s*Reasoning\s*[\s\S]*?(?=\n\n|$)', '', assistant_response, flags=re.IGNORECASE)
        assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
        assistant_response = extract_last_c_code(assistant_response)
        return assistant_response

    def run(self,file_name=None):
        """主逻辑"""

        if file_name == None:
            args = self.parse_args()

            input_c_file_path = f"input/{args.file_name}"
            output_c_file_path = f"output/{args.file_name}"
        else :
            input_c_file_path = f"input/{file_name}"
            output_c_file_path = f"output/{file_name}"
            
        # 获取用户提示
        user_prompt = self.get_user_prompt(input_c_file_path)
        if not user_prompt:
            return  # 如果读取文件失败，直接返回
        

        # 获取 ACSL 注释
        annotations = self.get_annotations(user_prompt)
        print(annotations)

        # 将 ACSL 注释写入输出文件
        with open(output_c_file_path, 'w', encoding='utf-8') as file:
            file.write(annotations)



if __name__ == "__main__":
    generator = InvGenerator()
    generator.run()