import openai
import argparse
import json
import re
from loopAnalysis import LoopAnalysis
from outputVerify import OutputVerifier
from loopProcessor import LoopProcessor

class InvGenerator:
    def __init__(self):
        # OpenAI 客户端初始化
        # self.llm ='gpt-3.5-turbo'
        #self.llm ='claude-3-7-sonnet-20250219-thinking'
        # self.llm = 'deepseek-v3'
        self.llm = 'gpt-4o'
        # self.llm = 'gpt-4o'
        
        self.client = openai.OpenAI(
            base_url="https://yunwu.ai/v1",
            api_key="sk-hfyQZDWdgyc4oQnDw4nvOh6KT1iDQ5EbNy9UjQwnMzBntefe"
        )
        # 初始化消息列表
        self.messages = [
            {"role": "system", "content": "You are a helpful assistant."}
        ]
    

    def filter_conditon(self,condition):
        if condition:
            return re.sub(r'(\w+)@pre', r'\\at(\1, Pre)', condition)
        else:
            return condition
    
    
    
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

    def get_annotated_loop_content(self,code,ridx):
        code_list = list(code)
        
        # 查找所有的 for 或 while 循环位置
        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        matches = list(re.finditer(loop_pattern, code))
       
        at_index = 0
        end_index = -1
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
        annotated_loop_content = ''.join(code_list[at_index:end_index]) 
            
        # 将字符列表重新拼接成字符串
        return annotated_loop_content
    
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
    
    def append_const_annotations(self,annotations, unchanged_vars,var_map,path_cond=None):
        # n == \at(n,Pre)
        invariant_annotations = []
        for var_name in unchanged_vars:
            if var_name in var_map:
                value = self.filter_conditon(var_map[var_name])
                if path_cond !=None :
                    invariant_annotations.append(f"loop invariant ({path_cond}) ==> ({var_name} == {value});")
                else:
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
    
    def append_inner_annotations(self,annotations,key):
        updated_code = []
        invariant_annotation = f"loop invariant PLACE_HOLDER_{key} ;" 
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


    

    def append_notin_annotations(self, annotations, var_map , updated_loop_condition,path_cond=None):
        invariant_annotation = None

        init_invariants = []
        for var in var_map:
            init_value = var_map[var]
            init_value = self.filter_conditon(init_value)
            init_invariants.append( f'({var} == {init_value})')
        
        init_invariant = '&&'.join(init_invariants)

        def contains_no_letters(updated_loop_condition):

            if updated_loop_condition == None:
                return True

            if 'unknown' in updated_loop_condition :
                return True
            
            # 检查字符串中是否含有字母
            if re.search(r'[a-zA-Z]', updated_loop_condition):
                return False  # 含有字母
            else:
                return True  # 不含字母
            
        if not contains_no_letters(updated_loop_condition):

            if path_cond !=None :
                invariant_annotation = f"loop invariant ({path_cond}) ==> ((!({updated_loop_condition})) ==> ({init_invariant}));"
            else:
                invariant_annotation = f"loop invariant (!({updated_loop_condition})) ==> ({init_invariant});"



        # Iterate through the annotations
        updated_code = []
        found_first_annotation = False

        for line in annotations.splitlines():
            if not found_first_annotation and '/*@' in line:
            # Append the current line
                updated_code.append(line)
            # Insert the invariant annotations below the first occurrence of /*@
                if invariant_annotation:
                    updated_code.append(f"          {invariant_annotation}")
                    found_first_annotation = True
            else:
            # Keep other lines as they are
                updated_code.append(line)

       # Join the list back into a single string and return
        return "\n".join(updated_code)

    def append_array_annotations(self,annotations,array_name):
        updated_code = []
        invariant_annotation = f"loop invariant PLACE_HOLDER_FOR_ARRAY_{array_name} ;" 
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

    
    def append_non_inductive_annotations(self,annotations,var_map,updated_loop_condition,key, path_cond=None):

        invariant_annotation = None

        init_invariants = []
        for var in var_map:
            init_value = var_map[var]
            init_value = self.filter_conditon(init_value)
            init_invariants.append( f'({var} == {init_value})')
        
        init_invariant = '&&'.join(init_invariants)

        
        def contains_no_letters(updated_loop_condition):

            if updated_loop_condition == None:
                return True
            # 检查字符串中是否含有字母
            if  'unknown' in updated_loop_condition:
                return True

            if re.search(r'[a-zA-Z]', updated_loop_condition):
                return False  # 含有字母
            else:
                return True  # 不含字母
            



        if contains_no_letters(updated_loop_condition) :
                if path_cond!=None:
                    invariant_annotation = f"loop invariant  ({path_cond}) ==> (({init_invariant}) || (PLACE_HOLDER_{key})) ;" 
                else:
                    invariant_annotation = f"loop invariant  ({init_invariant}) || (PLACE_HOLDER_{key}) ;" 
        else:
                if path_cond!=None:
                    invariant_annotation = f"loop invariant  ({path_cond}) ==> (({updated_loop_condition}) ==> (({init_invariant}) || (PLACE_HOLDER_{key}))) ;" 
                else:
                    invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> (({init_invariant}) || (PLACE_HOLDER_{key}));"

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


    def append_annotations(self,annotations,var_map,updated_loop_condition,key, path_cond=None):

        invariant_annotation = None

        init_invariants = []
        for var in var_map:
            init_value = var_map[var]
            init_value = self.filter_conditon(init_value)
            init_invariants.append( f'({var} == {init_value})')
        
        init_invariant = '&&'.join(init_invariants)

        
        def contains_no_letters(updated_loop_condition):

            if updated_loop_condition == None:
                return True
            # 检查字符串中是否含有字母
            if  'unknown' in updated_loop_condition:
                return True

            if re.search(r'[a-zA-Z]', updated_loop_condition):
                return False  # 含有字母
            else:
                return True  # 不含字母
            



        if contains_no_letters(updated_loop_condition):
                if path_cond!=None:
                    invariant_annotation = f"loop invariant  ({path_cond}) ==> (({init_invariant}) || (PLACE_HOLDER_{key})) ;" 
                else:
                    invariant_annotation = f"loop invariant  ({init_invariant}) || (PLACE_HOLDER_{key}) ;" 
        else:
                if path_cond!=None:
                    invariant_annotation = f"loop invariant  ({path_cond}) ==> (({updated_loop_condition}) ==> (({init_invariant}) || (PLACE_HOLDER_{key}))) ;" 
                else:
                    invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> (({init_invariant}) || (PLACE_HOLDER_{key}));"


        
        
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
    
    def repair(self,syntax_error,annotations,output_c_file_path):
        annotations = self.repair_annotations(syntax_error,annotations)  

        print("after repair")

        print(annotations)

        # 将 ACSL 注释写入输出文件
        with open(output_c_file_path, 'w', encoding='utf-8') as file:
            file.write(annotations)

        return annotations

    def regen(self,validate_result,syntax_error,annotations,output_c_file_path):

        annotations = self.mark_failed_invariants(annotations,validate_result)
        print(annotations)

        annotations = self.regen_annotations(syntax_error,annotations)  

        print("after regen")

        print(annotations)


        # 将 ACSL 注释写入输出文件
        with open(output_c_file_path, 'w', encoding='utf-8') as file:
            file.write(annotations)

        return annotations


    def strength(self,error_list,annotations,output_c_file_path):

        annotations = self.strength_annotations(error_list,annotations)
        

        print("after strength")

        print(annotations)


        # 将 ACSL 注释写入输出文件
        with open(output_c_file_path, 'w', encoding='utf-8') as file:
            file.write(annotations)
        
        return annotations

    def weaken(self,validate_result,error_list,annotations,output_c_file_path):

        annotations = self.mark_failed_invariants(annotations,validate_result)
        print(annotations)
        
        annotations = self.weaken_annotations(error_list,annotations)

        print("after weaken")

        print(annotations)

        # 将 ACSL 注释写入输出文件
        with open(output_c_file_path, 'w', encoding='utf-8') as file:
            file.write(annotations)

        return annotations

    def hudini(self,valid,file_name,annotations,output_c_file_path):
        ht = 0
            
        while valid != True and ht <= 5:
                
            verifier = OutputVerifier()
            verifier.run(file_name)   # 传入完整路径

            validate_result = verifier.validate_result
                    
            if len(validate_result) <= 1:
                     break

            valid = bool(validate_result) and all(validate_result)

            

            annotations = self.hudini_annotations(validate_result,annotations)

            print("after hudini")

            print(annotations)


            # 将 ACSL 注释写入输出文件
            with open(output_c_file_path, 'w', encoding='utf-8') as file:
                    file.write(annotations)

            ht = ht +1
        return annotations

    
    def get_user_prompt(self, loop_content,pre_condition):

        # 从文件中读取 prompt 模板
        with open("prompt/gen.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # 替换模板中的 {code} 占位符
        user_prompt = prompt_template.format(content=loop_content,pre_cond = pre_condition)

        return user_prompt
    
    def get_simgen_prompt(self, loop_content):
         # 从文件中读取 prompt 模板
        with open("prompt/simgen.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # 替换模板中的 {code} 占位符
        simgen_prompt = prompt_template.format(content=loop_content)
        return simgen_prompt
    
    def get_convert_prompt(self,annotations):
        # 从文件中读取 prompt 模板
        with open("prompt/convert.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # 替换模板中的 {code} 占位符
        convert_prompt = prompt_template.format(loop_inv = annotations)

        return convert_prompt

    def get_error_prompt(self,error_message, c_code):
         # 从文件中读取 prompt 模板
        with open("prompt/error.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # 替换模板中的 {code} 占位符
        error_prompt = prompt_template.format(error_str = error_message , c_code= c_code)
        return error_prompt
    
    def get_weaken_prompt(self,error_message, c_code):
         # 从文件中读取 prompt 模板
        with open("prompt/weaken.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # 替换模板中的 {code} 占位符
        weaken_prompt = prompt_template.format(error_str = error_message , c_code= c_code)
        return weaken_prompt
    
    def get_regen_prompt(self,error_message, c_code):
         # 从文件中读取 prompt 模板
        with open("prompt/regen.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # 替换模板中的 {code} 占位符
        regen_prompt = prompt_template.format(error_str = error_message , c_code= c_code)
        return regen_prompt
    
    
    def get_strength_prompt(self,error_message, c_code):
        # 从文件中读取 prompt 模板
        with open("prompt/strength.txt", "r", encoding="utf-8") as file:
            prompt_template = file.read()

        # 替换模板中的 {code} 占位符
        strength_prompt = prompt_template.format(error_str = error_message , c_code= c_code)
        return strength_prompt
    
    def repair_annotations(self, error_message, c_code):
        """调用大模型生成ACSL规约"""

        prompt = self.get_error_prompt(error_message, c_code)

        try:
            """调用 OpenAI API 获取 ACSL 注释"""
            # 将内容添加到消息中
            self.messages.append({"role": "user", "content": prompt})
        
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
            assistant_response = re.sub(r'>\s*Reasoning\s*[\s\S]*?(?=\n\n|$)', '', assistant_response, flags=re.IGNORECASE)
            assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
            assistant_response = extract_last_c_code(assistant_response)

            return assistant_response

        except Exception as e:
            print(f"API调用失败: {e}")
            return None
    
        
    def weaken_annotations(self, error_list, c_code):
            """调用大模型生成ACSL规约"""

            def format_errors(error_list):
                if not error_list:
                    return "No errors found."

                error_str = []

                for index, (desc, location, content) in enumerate(error_list, start=1):
                    error_str.append(f"Error {index}: {desc}")
                    error_str.append(f"Location: {location}")
                    error_str.append(f"Code: {content}")
                    error_str.append("-" * 50)

                return "\n".join(error_str)

            error_str = format_errors(error_list)

            prompt = self.get_weaken_prompt(error_str, c_code)

            try:
                """调用 OpenAI API 获取 ACSL 注释"""
                # 将内容添加到消息中
                self.messages.append({"role": "user", "content": prompt})
            
                # 获取助手的响应
                response = self.client.chat.completions.create(
                    model= self.llm,
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

            except Exception as e:
                print(f"API调用失败: {e}")
                return None
            
    def strength_annotations(self, error_list, c_code):
            """调用大模型生成ACSL规约"""

            def format_errors(error_list):
                if not error_list:
                    return "No errors found."

                error_str = []

                
               
                for index, (desc, location, content) in enumerate(error_list, start=1):
                    error_str.append(f"Error {index}: {desc.split}")
                    error_str.append(f"Location: {location}")
                    error_str.append(f"Code: {content}")
                    error_str.append("-" * 50)

                return "\n".join(error_str)

            error_str = format_errors(error_list)

            prompt = self.get_strength_prompt(error_str, c_code)

            try:
                """调用 OpenAI API 获取 ACSL 注释"""
                # 将内容添加到消息中
                self.messages.append({"role": "user", "content": prompt})
            
                # 获取助手的响应
                response = self.client.chat.completions.create(
                    model= self.llm,
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

            except Exception as e:
                print(f"API调用失败: {e}")
                return None
    

    def regen_annotations(self, error_list, c_code):
            """调用大模型生成ACSL规约"""

            def format_errors(error_list):
                if not error_list:
                    return "No errors found."

                error_str = []

                

                for index, (desc, location, content) in enumerate(error_list, start=1):
                    error_str.append(f"Error {index}: {desc}")
                    error_str.append(f"Location: {location}")
                    error_str.append(f"Code: {content}")
                    error_str.append("-" * 50)

                return "\n".join(error_str)

            error_str = format_errors(error_list)

            prompt = self.get_regen_prompt(error_str, c_code)

            try:
                """调用 OpenAI API 获取 ACSL 注释"""
                # 将内容添加到消息中
                self.messages.append({"role": "user", "content": prompt})
            
                # 获取助手的响应
                response = self.client.chat.completions.create(
                    model= self.llm,
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

            except Exception as e:
                print(f"API调用失败: {e}")
                return None



    def hudini_annotations(self, validate_result, annotations):
        # 构建匹配模式
        pattern = re.compile(
            r'^(\s*)loop\s+invariant\b[\s\S]*?;(.*?)(\n|$)', 
            flags=re.MULTILINE
        )

        # 使用索引跟踪当前匹配项
        current_index = [0]  # 使用list实现闭包内的数值修改

        # 替换处理器
        def replacer(match):
            # 获取当前匹配项的判定结果
            if current_index[0] < len(validate_result):
                should_keep = validate_result[current_index[0]]
                current_index[0] += 1
            else:
                # 如果数组长度不足，默认保留
                should_keep = True

            # 返回空字符串删除false项，保留true项
            return '' if not should_keep else match.group(0)

        # 执行全局替换
        return pattern.sub(replacer, annotations)


    def convert_annotations(self, annotations):

        print (annotations)

        index = annotations.find("*/")
        if index != -1:
            before = annotations[:index + 2]  # 包含 '*/'
            after = annotations[index + 2:]
        
        def replace_at(match):
            variable = match.group(1).strip()
            return f"{variable}@pre"
        
        def replace_forall(match):
            variable = match.group(1).strip()
            return f"forall ({variable}:Z),"
    
        def replace_exists(match):
            variable = match.group(1).strip()
            return f"exists ({variable}:Z),"


        parts = before.strip()[3:-2].split('loop invariant')
        invariants = [f'({part.strip()})' for part in parts if part.strip()]
        invariant = ' &&\n'.join(invariants)
        invariant = re.sub(r'\\forall\s+(?:int|integer)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*;' , replace_forall, invariant)
        invariant = re.sub(r'\\exists\s+(?:int|integer)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s*;' , replace_exists, invariant)
        invariant = re.sub(r'\\at\(\s*([a-zA-Z0-9_\[\]\->\.\*]+)\s*,\s*Pre\s*\)', replace_at, invariant)
        invariant = re.sub(r'([a-zA-Z_][a-zA-Z0-9_]*)\[', r'\1_l[', invariant)
        invariant = re.sub(r'(<|<=)\s+([a-zA-Z_][a-zA-Z0-9_]*)\s+(<|<=)', r'\1 \2 && \2 \3', invariant)
        invariant = invariant.replace("==>", "=>")
        invariant = invariant.replace(';','')

        before = f'''/*@ Inv
    {invariant}
    */
    ''' 
        return before+after
    

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
    
    def simple_get_annotations(self, user_prompt):
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
    
    def mark_failed_invariants(self,code, validation_results):
        # 匹配所有循环不变量语句
        invariant_pattern = re.compile(r'loop invariant (.*?);\n', re.DOTALL)
        
        # 找到所有不变量及其位置
        matches = list(invariant_pattern.finditer(code))
        
        # 创建可修改的代码列表
        code_list = list(code)
        offset = 0
        
        # 遍历验证结果并标注失败项
        for idx, valid in enumerate(validation_results):
            if not valid and idx < len(matches):
                match = matches[idx]
                
                # 计算实际位置（考虑之前修改的偏移量）
                start = match.start(1) + offset
                end = match.end(1) + offset
                
                # 添加标记
                marked = f"{match.group(1)} [INVARIANT FAILED] "
                
                # 替换内容并更新偏移量
                code_list[start:end] = list(marked)
                offset += len(marked) - (end - start)
        
        return ''.join(code_list)

    def run(self,file_name=None):
        """主逻辑"""

        if file_name == None:
            args = self.parse_args()
            file_name = args.file_name

        
        name = file_name.split('.')[0]
  
        input_c_file_path = f"input/{file_name}"
        output_c_file_path = f"output/{file_name}"
        output_symexe_c_file_path = f"symexe/output/{file_name}"
        

        json_file =f'loop/{name}.json'


        processor = LoopProcessor(file_name)
        processor.init_execute()
        processor.execute()
        sorted_indices = processor.sorted_indices
        inner_flags = processor.inner_flags
        tag = '/* >>> LOOP INVARIANT TO FILL <<< */'
        single_loop = len(sorted_indices) == 1
        
       
        for idx in sorted_indices:

                print(f"INNER_FLAG: {inner_flags[idx]}")
                
                if idx == sorted_indices[0]:
                    code = self.get_c_code(input_c_file_path)
                else:
                    code = self.get_c_code(output_c_file_path)
                
                
                loop = self.get_json_at_index(json_file,idx)
                # loop_content =loop.get('content')
                loop_content = processor.get_loop_content(code,idx)
                pre_condition =loop.get('condition')
                pre_condition =self.filter_conditon(pre_condition)
                tag = f'''
        /* >>> LOOP INVARIANT TO FILL <<< */
        '''
                
                
                annotations =f'''
                {tag}
                /*@
                */
                {loop_content}
                ''' 

                analysis = LoopAnalysis(json_file,idx)
                analysis.run()
                
                unchanged_vars =analysis.global_unchanged_vars

                var_maps = analysis.var_maps
                print(var_maps)
                path_conds =analysis.path_conds
                print(path_conds)
                updated_loop_conditions = analysis.updated_loop_conditions
                array_names = analysis.array_names
                non_inductive_vars = analysis.non_inductive_vars

                simple = False

                if not inner_flags[idx]:

                    for var_map, path_cond,updated_loop_condition in zip(var_maps, path_conds,updated_loop_conditions):

                                if single_loop:
                                    path_cond = None
                                if path_cond != None:
                                    path_cond =self.filter_conditon(path_cond)

                                annotations  = self.append_const_annotations(annotations,unchanged_vars,var_map,path_cond)

                                print(annotations)

                                updated_loop_condition = self.filter_conditon(updated_loop_condition)

                                annotations  = self.append_notin_annotations(annotations,var_map,updated_loop_condition,path_cond)
                                    
                                for key in var_map.keys():
                                    if key not in unchanged_vars:
                                        if key in non_inductive_vars:
                                            annotations  = self.append_non_inductive_annotations(annotations,var_map,updated_loop_condition,key,path_cond)
                                        else:
                                            annotations  = self.append_annotations(annotations,var_map,updated_loop_condition,key,path_cond)
                                    
                                print(annotations)

                else:
                    simple = True
                    var_map = var_maps[0]
                    for key in var_map.keys():
                        annotations  = self.append_inner_annotations(annotations,key)

                
                if array_names:
                    for array_name in array_names:
                        annotations = self.append_array_annotations(annotations,array_name)


                
                annotations = self.update_loop_content(code,annotations,idx)
                print(annotations)

                
                
                if simple:
                    print("SIMPLE")
                    user_prompt = self.get_simgen_prompt(annotations)
                    if not user_prompt:
                        return  # 如果读取文件失败，直接返回
                    annotations = self.simple_get_annotations(user_prompt)
                else:
                    # 获取用户提示
                    user_prompt = self.get_user_prompt(annotations,pre_condition)
                    if not user_prompt:
                        return  # 如果读取文件失败，直接返回
                    annotations = self.get_annotations(user_prompt)
                                                                                                                                                                                                                                                                                                                                                                                                                                                    
                

                annotations = annotations.replace(tag,'')

                print(annotations)

                for var_map, path_cond in zip(var_maps, path_conds):  
                    
                    if path_cond != None:
                        path_cond =self.filter_conditon(path_cond)

                
                    for var in var_map.keys():
                        replacement = self.filter_conditon(var_map[var])

                        if path_cond == None:
                            annotations = annotations.replace(f'\\at({var}, Pre)',replacement)

                        else:
                            annos = annotations.split(';')
                            nannos = []

                            for anno in annos:
                                if path_cond in anno:
                                    anno = anno.replace(f'\\at({var}, Pre)',replacement)
                                    nannos.append(anno)
                                else:
                                    nannos.append(anno)


                            annotations = ';'.join(nannos)
                    
                    
                print(annotations)


                # 将 ACSL 注释写入输出文件
                with open(output_c_file_path, 'w', encoding='utf-8') as file:
                    file.write(annotations)

                

                annotations = self.get_annotated_loop_content(annotations,idx)

                annotations = self.convert_annotations(annotations)

                print('转换后')
                print(annotations)

                
                symexe_updated_code  =processor.update_loop_content(self.get_c_code(processor.output_file),annotations,idx)

                with open( output_symexe_c_file_path, 'w', encoding='utf-8') as file:
                                    file.write(symexe_updated_code)

                processor.execute()

                    


        verifier = OutputVerifier()
        verifier.run(file_name) 

        validate_result = verifier.validate_result
        verify_result = verifier.verify_result
        syntax_error = verifier.syntax_error

        valid = bool(validate_result) and all(validate_result)
        syntax = syntax_error ==''
        satisfy = all(verify_result)

        if syntax and valid and satisfy:
            print("CORRECT INVARIANT")

        



if __name__ == "__main__":
    generator = InvGenerator()
    generator.run()







