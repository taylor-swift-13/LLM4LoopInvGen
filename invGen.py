import openai
import argparse
import json
import re
from loopProcessor import LoopProcessor
from loopAnalysis import LoopAnalysis



class InvGenerator:
    def __init__(self):
        # OpenAI 客户端初始化
        self.client = openai.OpenAI(
            base_url="https://yunwu.ai/v1",
            api_key="my-key"
        )
        # 初始化消息列表
        self.messages = [
            {"role": "system", "content": "You are a helpful assistant."}
        ]

    def update_loop_content(self,code,new_loop_content,ridx):
        # 将代码拆分成单字符的列表
        code_list = list(code)
        
        # 查找所有的 for 或 while 循环位置
        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        matches = list(re.finditer(loop_pattern, code))
        
        # 处理每一个循环
        for idx, match in enumerate(matches):
            # 循环的起始位置
            if idx == ridx:

                loop_start = match.start()  
                 
                at_index = -1  # 默认值，如果没有找到 '@' 就返回 -1
                for i in range(loop_start - 1, -1, -1):  # 从 loop_start - 1 开始，反向遍历
                    if code_list[i] == '@':
                        at_index = i
                        break  # 找到第一个 '@'，跳出循环

                at_index = at_index -2

                # 在循环后找到第一个 { 对应的 }
                brace_count = 0
                loop_end = match.end()
                end_index = loop_end
                while brace_count >= 0:
                    if code_list[end_index] == '{':
                        brace_count += 1
                    elif code_list[end_index] == '}':
                        brace_count -= 1
                    end_index += 1
        
        # 替换循环内容
        updated_code = (
            ''.join(code_list[:at_index]) +  # 循环之前的部分
            new_loop_content +                   # 替换后的循环内容
            ''.join(code_list[end_index:])   # 循环之后的部分
        )
            
        # 将字符列表重新拼接成字符串
        return updated_code
    


    def get_json_at_index(self,json_file, idx):
        with open(json_file, 'r') as file:
            data = json.load(file)  # 读取并解析 JSON 文件
            
            if isinstance(data, list) and 0 <= idx < len(data):
                return data[idx]  # 返回第 idx 个 JSON 对象
            else:
                raise IndexError("Index out of range or data is not a list")
        
    def parse_args(self):
        """设置命令行参数解析器"""
        parser = argparse.ArgumentParser(description="Run Frama-C WP on a C file.")
        parser.add_argument('file_name', help="Path to the C file to analyze")
        return parser.parse_args()


    def get_user_prompt(self, full_code, loop_content,pre_condition):

        # 从文件中读取 prompt 模板
        with open("prompt/prompt_1.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        with open("prompt/few-shots.txt", "r", encoding="utf-8") as file:
            few_shots = file.read()
        
        # 将 few-shot 示例插入到 prompt 中
        updated_prompt = prompt_template.replace('{few_shot_examples}', few_shots)


        # 替换模板中的 {code} 占位符
        user_prompt = updated_prompt.format(code = full_code,content = loop_content,pre_cond = pre_condition)

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
    
    def append_const_annotations(self, annotations, unchanged_vars,var_map):
        # n == \at(n,Pre)
        invariant_annotations = []
        for var_name in unchanged_vars:
            if var_name in var_map:
                value = var_map[var_name]
                invariant_annotations.append(f" {var_name} == {value} ")
                # Iterate through the annotations

        # 用 " && " 连接不变式注解
        invariant_str = " && ".join(invariant_annotations)

        if invariant_str != None:
            # 替换目标字符串
            target = "/*@ Inv emp */"
            replacement = f'''/*@Inv   
                    {invariant_str}
                    >>> INFILL LOOP INVARIANT HERE <<<  */'''
            updated_code = annotations.replace(target, replacement)

        return updated_code


    def get_annotations(self, user_prompt):
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

    def run(self,file_name=None):
        """主逻辑"""


        c_file_name = None
        if file_name == None:
            args = self.parse_args()
            input_c_file_path = f"input/{args.file_name}"
            output_c_file_path = f"output/{args.file_name}"
            c_file_name = args.file_name

        else :
            input_c_file_path = f"input/{file_name}"
            output_c_file_path = f"output/{file_name}"
            c_file_name = file_name

        input_code = self.get_c_code(input_c_file_path)

        # 创建 LoopProcessor 对象并执行
        
        processor = LoopProcessor(c_file_name)
        processor.init_execute()
        processor.execute()
        json_file = processor.json_file
        sorted_indices = processor.sorted_indices

        output_code = self.get_c_code(output_c_file_path)

        for idx in sorted_indices:

            loop = self.get_json_at_index(json_file,idx)
            loop_content =loop.get('content')
            pre_conditon =loop.get('condition')

            annotations =f'''
            {loop_content}
            '''

            analysis = LoopAnalysis(json_file,idx)
            analysis.run()

            unchanged_vars =analysis.unchanged_vars
            var_map = analysis.var_map
            annotations  = self.append_const_annotations(annotations,unchanged_vars,var_map)

            print(annotations)
            
            
            user_prompt = self.get_user_prompt(input_code,annotations,pre_conditon)
            if not user_prompt:
                return  
            
            annotations = self.get_annotations(user_prompt)
            print(annotations)

            updated_code = self.update_loop_content(output_code,annotations,idx)

             # 将 ACSL 注释写入输出文件
            with open(output_c_file_path, 'w', encoding='utf-8') as file:
                file.write(updated_code)

            processor.execute()


            
            


if __name__ == "__main__":
    generator = InvGenerator()
    generator.run()