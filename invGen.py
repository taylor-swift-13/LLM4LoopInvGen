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
        # self.llm ='claude-3-7-sonnet-thinking'
        # self.llm = 'deepseek-v3'
        self.llm = 'gpt-4o-mini'
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

            valid_error_list = verifier.valid_error_list

            annotations = self.hudini_annotations(valid_error_list,annotations)

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
                temperature=0.3
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
                    temperature=0.3
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
                    error_str.append(f"Error {index}: {desc}")
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
                    temperature=0.3
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
                    temperature=0.3
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



    def hudini_annotations(self,valid_error_list, annotations):
        """智能删除包含错误行的完整循环不变式块，确保每个错误行只匹配一次"""
        # 1. 提取错误行内容（保留原始格式）
        error_lines = []
        for error in valid_error_list:
            parts = error[2].split(':', 1)
            error_line = parts[1].strip() if len(parts) > 1 else parts[0].strip()
            error_line=error_line.replace('/*@',' ').strip()
            error_lines.append(error_line)
        
        # 2. 构建匹配模式（精确匹配每个循环不变式块）
        pattern = re.compile(
            r'\s*loop\s+invariant\b[\s\S]*?;(?:\s*\n|$)',  # 匹配循环不变式块，以;结尾后跟换行或字符串结束
            flags=re.DOTALL
        )

        # 3. 使用集合来跟踪已匹配的错误行
        used_errors = set()

        # 4. 替换处理器
        def replacer(match):
            full_match = match.group(0)
            invariant_line = full_match.strip()
            normalized_invariant = invariant_line.rstrip(';').strip()
            
            for i, error_line in enumerate(error_lines):
                if i in used_errors:
                    continue
                normalized_error = error_line.rstrip(';').strip()
                # 部分匹配检查（错误行可能是invariant的一部分）
                if normalized_error in normalized_invariant:
                    used_errors.add(i)  # 标记该错误行已使用
                    return ''  # 删除匹配的循环不变式块
            
            return full_match  # 没有匹配的错误行则保留

        # 5. 执行替换
        return pattern.sub(replacer, annotations)


    def convert_annotations(self, annotations):

        """调用大模型生成ACSL规约"""

        prompt =  self.get_convert_prompt(annotations)

        try:
            """调用 OpenAI API 获取 ACSL 注释"""
            # 将内容添加到消息中
            self.messages.append({"role": "user", "content": prompt})
        
            # 获取助手的响应
            response = self.client.chat.completions.create(
                model= self.llm,
                messages=self.messages,
                temperature=0.3
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

    def get_annotations(self, user_prompt):
        """调用 OpenAI API 获取 ACSL 注释"""
        # 将内容添加到消息中
        self.messages.append({"role": "user", "content": user_prompt})

        # 获取助手的响应
        response = self.client.chat.completions.create(
            model=self.llm,
            messages=self.messages,
            temperature=0.3
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
    /* >>> LOOP INVARIANT TO FILL <<< 
       >>> PRECONDITION OF THE LOOP : {pre_condition} <<< */
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

            if not inner_flags[idx]:

                for var_map, path_cond,updated_loop_condition in zip(var_maps, path_conds,updated_loop_conditions):

                            if path_cond != None:
                                path_cond =self.filter_conditon(path_cond)

                            annotations  = self.append_const_annotations(annotations,unchanged_vars,var_map,path_cond)

                            print(annotations)


                            updated_loop_condition = self.filter_conditon(updated_loop_condition)

                            annotations  = self.append_notin_annotations(annotations,var_map,updated_loop_condition,path_cond)
                            
                            for key in var_map.keys():
                                if key not in unchanged_vars:
                                    annotations  = self.append_annotations(annotations,var_map,updated_loop_condition,key,path_cond)
                            
                            print(annotations)

            else:
                for var_map in var_maps:
                    for key in var_map.keys():
                        annotations  = self.append_inner_annotations(annotations,key)


            
            annotations = self.update_loop_content(code,annotations,idx)
            print(annotations)

            # 获取用户提示
            user_prompt = self.get_user_prompt(annotations,pre_condition)
            if not user_prompt:
                return  # 如果读取文件失败，直接返回
                                                                                                                                                                                                                                                                                                                                                                                                                                                

            #  获取 ACSL 注释
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

            if not inner_flags[idx]:
                valid = False
                for _ in range(3):

                    verifier = OutputVerifier()
                    verifier.run(file_name)   # 传入完整路径
                    
                    # 获取验证结果（假设返回的是列表）
                    validate_result = verifier.validate_result
                    verify_result = verifier.verify_result
                    syntax_error = verifier.syntax_error

                    # 判断验证结果
                    valid = bool(validate_result) and all(validate_result)
                    syntax = syntax_error ==''
                    satisfy = all(verify_result)

                    if not syntax:

                        annotations = self.repair(syntax_error,annotations,output_c_file_path)


                    elif not valid or (not satisfy and idx == sorted_indices[-1]):

                        error_list = verifier.valid_error_list + verifier.verify_error_list

                        if valid:

                            annotations  = self.strength(error_list,annotations,output_c_file_path)

                        elif satisfy:

                            annotations  = self.weaken(validate_result,error_list,annotations,output_c_file_path)

                        else:

                            annotations  = self.regen(validate_result,error_list,annotations,output_c_file_path)

                    else:
                        break

                
                annotations  = self.hudini(valid,file_name,annotations,output_c_file_path)
                        
                verifier = OutputVerifier()
                verifier.run(file_name)   


                annotations = self.convert_annotations(annotations)
                print(annotations)
                # 将 ACSL 注释写入输出文件
                with open( output_symexe_c_file_path, 'w', encoding='utf-8') as file:
                        file.write(annotations)
                processor.execute()

        



if __name__ == "__main__":
    generator = InvGenerator()
    generator.run()







