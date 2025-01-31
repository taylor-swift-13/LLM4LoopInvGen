import openai
import argparse
import json
import re
from loopAnalysis import LoopAnalysis

class InvGenerator:
    def __init__(self):
        # OpenAI 客户端初始化
        self.client = openai.OpenAI(
            base_url="https://yunwu.ai/v1",
            api_key="sk-S3fNVvxTTDcQymGTYJU35ZheQZ6cON1zZW0rMGeM8F1nIA6l"
        )
        # 初始化消息列表
        self.messages = [
            {"role": "system", "content": "You are a helpful assistant."}
        ]
    

    def filter_conditon(self,condition):
        return re.sub(r'(\w+)@pre', r'\\at(\1, Pre)', condition)
    
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
            ''.join(code_list[:loop_start]) +  # 循环之前的部分
            new_loop_content +                   # 替换后的循环内容
            ''.join(code_list[end_index:])   # 循环之后的部分
        )
            
        # 将字符列表重新拼接成字符串
        return updated_code
    
    def extract_var_map_from_state(self,text):
        
        var_map = {}
        # 正则表达式匹配形如 "var == value" 的部分，支持嵌套括号
        pattern = r'(\w+)\s*==\s*(\((?:[^()]*|\((?:[^()]*|\([^()]*\))*\))*\)|[^()]+)'
        matches = re.findall(pattern, text)

        for var, value in matches:
            # 去掉 value 中的外层括号（如果存在）
            value = value.strip()
            if value.startswith('(') and value.endswith(')'):
                value = value[1:-1]
            var_map[var] = value

        return var_map
    
    def append_const_annotations(self, annotations, unchanged_vars,var_map):
        # n == \at(n,Pre)
        invariant_annotations = []
        for var_name in unchanged_vars:
            if var_name in var_map:
                value = self.filter_conditon(var_map[var_name])
                invariant_annotations.append(f"loop invariant {var_name} == {value};")
                # Iterate through the annotations

        updated_code = []
        found_first_annotation = False

        for line in annotations.splitlines():
            if not found_first_annotation and '/*@' in line:
            # Append the current line
                updated_code.append(line)
            # Insert the invariant annotations below the first occurrence of /*@
                for inv in invariant_annotations:
                    updated_code.append(f"          {inv}")
                found_first_annotation = True
            else:
            # Keep other lines as they are
                updated_code.append(line)

       # Join the list back into a single string and return
        return "\n".join(updated_code)
    
    def append_simple_annotations(self, annotations, ver_map , updated_loop_condition, cond, key, value):
    
        invariant_annotation = ''

        init_value = ver_map[key]

        init_value = self.filter_conditon(init_value)
        value = self.filter_conditon(value)
        cond = self.filter_conditon(cond)

        if cond == '':
            invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> ( ({key} == {init_value})|| ({key} == {value}) );"
        else:
            invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> ({cond}) ==>  ( ({key} == {init_value})|| ({key} == {value}) );"
        # Iterate through the annotations

        updated_code = []
        found_first_annotation = False

        for line in annotations.splitlines():
            if not found_first_annotation and '/*@' in line:
            # Append the current line
                updated_code.append(line)
            # Insert the invariant annotations below the first occurrence of /*@
                updated_code.append(f"          {invariant_annotation}")
                found_first_annotation = True
            else:
            # Keep other lines as they are
                updated_code.append(line)

       # Join the list back into a single string and return
        return "\n".join(updated_code)
    
    def append_medium_annotations(self,annotations, ver_map ,updated_loop_condition,key):
        
        init_value = ver_map[key]
        init_value = self.filter_conditon(init_value)
        
        invariant_annotation= f"loop invariant ({updated_loop_condition}) ==> ( ({key} == {init_value})|| PLACE_HOLDER_{key} );"

        updated_code = []
        found_first_annotation = False

        for line in annotations.splitlines():
            if not found_first_annotation and '/*@' in line:
            # Append the current line
                updated_code.append(line)
            # Insert the invariant annotations below the first occurrence of /*@
                updated_code.append(f"          {invariant_annotation}")
                found_first_annotation = True
            else:
            # Keep other lines as they are
                updated_code.append(line)

       # Join the list back into a single string and return
        return "\n".join(updated_code)
    
    def append_hard_annotations(self,annotations, updated_loop_condition,key):
        
        invariant_annotation= f"loop invariant ({updated_loop_condition}) ==> ( PLACE_HOLDER_{key} );"

        updated_code = []
        found_first_annotation = False

        for line in annotations.splitlines():
            if not found_first_annotation and '/*@' in line:
            # Append the current line
                updated_code.append(line)
            # Insert the invariant annotations below the first occurrence of /*@
                updated_code.append(f"          {invariant_annotation}")
                found_first_annotation = True
            else:
            # Keep other lines as they are
                updated_code.append(line)

       # Join the list back into a single string and return
        return "\n".join(updated_code)




    def get_json_at_index(self,json_file, idx):
        with open(json_file, 'r') as file:
            data = json.load(file)  # 读取并解析 JSON 文件
            
            if isinstance(data, list) and 0 <= idx < len(data):
                return data[idx]  # 返回第 idx 个 JSON 对象
            else:
                raise IndexError("Index out of range or data is not a list")
            
    
    def get_c_code(self, c_file_path):
        """从 C 文件中读取内容并生成用户提示"""
        try:
            with open(c_file_path, 'r') as file:
                c_code = file.read()
        except Exception as e:
            print(f"Error reading file {c_file_path}: {e}")
            return None

        return c_code

    def parse_args(self):
        """设置命令行参数解析器"""
        parser = argparse.ArgumentParser(description="Run Frama-C WP on a C file.")
        parser.add_argument('file_name', help="Path to the C file to analyze")
        return parser.parse_args()
    
    def get_user_prompt(self, full_code, loop_content,pre_condition):

        # 从文件中读取 prompt 模板
        with open("prompt/prompt_1.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # 替换模板中的 {code} 占位符
        user_prompt = prompt_template.format(code = full_code,content=loop_content,pre_cond = pre_condition)

        return user_prompt

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

        if file_name == None:
            args = self.parse_args()

            name = args.file_name.split('.')[0]

            input_c_file_path = f"input/{args.file_name}"
            output_c_file_path = f"output/{args.file_name}"
            json_file =f'loop/{name}.json'
        else :

            name = file_name.split('.')[0]

            input_c_file_path = f"input/{file_name}"
            output_c_file_path = f"output/{file_name}"
            json_file =f'loop/{name}.json'


        code = self.get_c_code(input_c_file_path)

        loop = self.get_json_at_index(json_file,0)
        loop_content =loop.get('content')
        pre_conditon =loop.get('condition')
        pre_conditon =self.filter_conditon(pre_conditon)
        

        
        annotations =f'''
        /*@
        */
        {loop_content}
        ''' 

        analysis = LoopAnalysis(json_file,0)
        analysis.run()
        
        unchanged_vars =analysis.unchanged_vars
        var_map = analysis.var_map
        annotations  = self.append_const_annotations(annotations,unchanged_vars,var_map)

        print(annotations)

        updated_loop_condition = analysis.updated_loop_condition
        # 使用正则表达式进行替换
        updated_loop_condition = self.filter_conditon(updated_loop_condition)


        unloop_paths = analysis.unloop_paths

        for path in unloop_paths:
            states = path['state']
            cond = path['path_condition']
            state_map = self.extract_var_map_from_state(states)
            print(state_map)
            
            for key in state_map.keys():
                if key not in unchanged_vars:
                    value = state_map[key]
                    if '@last' not in value and '@last' not in cond:
                        # 非迭代关系
                        annotations  = self.append_simple_annotations(annotations,var_map,updated_loop_condition,cond,key,value)

                    elif f"{key}@last" not in value:
                        annotations  = self.append_medium_annotations(annotations,var_map ,updated_loop_condition,key)
                    else :
                        annotations  = self.append_hard_annotations(annotations,updated_loop_condition,key)

        print(annotations)

        # 获取用户提示
        user_prompt = self.get_user_prompt(code,annotations,pre_conditon)
        if not user_prompt:
            return  # 如果读取文件失败，直接返回


        #  获取 ACSL 注释
        annotations = self.get_annotations(user_prompt)

        
        
        print(annotations)

        
        updated_code = self.update_loop_content(code,annotations,0)
        

        # # 将 ACSL 注释写入输出文件
        with open(output_c_file_path, 'w', encoding='utf-8') as file:
            file.write(updated_code)



if __name__ == "__main__":
    generator = InvGenerator()
    generator.run()