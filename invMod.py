import openai
import argparse
from syntaxChecker import SyntaxChecker

class InvModifier:
    def __init__(self,file_name,error_message):

        self.error_message = error_message
        self.file_name = file_name
        # OpenAI 客户端初始化
        self.client = openai.OpenAI(
            base_url="https://yunwu.ai/v1",
            api_key="my-key"
        )
        # 初始化消息列表
        self.messages = [
            {"role": "system", "content": "You are a helpful assistant."}
        ]


    def get_user_prompt(self, code,error_message):

        # 从文件中读取 prompt 模板
        with open("prompt/feedback.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()


        # 替换模板中的 {code} 占位符
        user_prompt = prompt_template.format(code = code,error_message = error_message)

        return user_prompt


    def get_c_code(self, c_file_path):
        """从 C 文件中读取内容并生成用户提示"""
        try:
            with open(c_file_path, 'r') as file:
                c_code = file.read()
        except Exception as e:
            print(f"Error reading file {c_file_path}: {e}")
            return None

        return c_code
    
    

    def get_modified_code(self, user_prompt):
        """调用 OpenAI API 获取 ACSL 注释"""
        # 将内容添加到消息中
        self.messages.append({"role": "user", "content": user_prompt})

        # 获取助手的响应
        response = self.client.chat.completions.create(
            model="gpt-4o",
            messages=self.messages,
            temperature=0.7
        )

        # 处理响应
        assistant_response = response.choices[0].message.content
        assistant_response = assistant_response.replace('```c', '').replace('```', '')
        return assistant_response

    def run(self):
        """主逻辑"""
        
        output_c_file_path = f"output/{self.file_name}"
            
        output_code = self.get_c_code(output_c_file_path)

        # 创建 LoopProcessor 对象并执行
        
        output_code = self.get_c_code(output_c_file_path)
            
        user_prompt = self.get_user_prompt(output_code,self.error_message)
        if not user_prompt:
                return  
            
        modified_code = self.get_modified_code(user_prompt)
        print(modified_code)

        # 将 ACSL 注释写入输出文件
        with open(output_c_file_path, 'w', encoding='utf-8') as file:
            file.write(modified_code)



if __name__ == "__main__":

    parser = argparse.ArgumentParser(description="Run Frama-C WP on a C file.")
    parser.add_argument('file_name', help="Path to the C file to analyze")
    file_name = parser.parse_args().file_name
   
    checker = SyntaxChecker()
    checker.run(file_name)
    error_message = checker.syntax_msg

    modifier = InvModifier(file_name,error_message)
    modifier.run()           