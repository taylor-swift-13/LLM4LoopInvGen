import openai
import argparse
import json
import re
from sympy import symbols, Eq, solve, sympify
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
    

    def append_notin_annotations(self, annotations, var_map , updated_loop_condition):
        invariant_annotation = ''

        init_invariants = []
        for var in var_map:
            init_value = var_map[var]
            init_value = self.filter_conditon(init_value)
            init_invariants.append( f'({var} == {init_value})')
        
        init_invariant = '&&'.join(init_invariants)

        def contains_no_letters(updated_loop_condition):
            # 检查字符串中是否含有字母
            if re.search(r'[a-zA-Z]', updated_loop_condition):
                return False  # 含有字母
            else:
                return True  # 不含字母
            
        if not contains_no_letters(updated_loop_condition):
            
            invariant_annotation = f"loop invariant (!({updated_loop_condition})) ==> ({init_invariant});"

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
            
        


    

    def append_special_annotations(self, annotations, var_map , updated_loop_condition, cond, key, value):
    
        invariant_annotation = ''

        print("simple")

        init_invariants = []
        for var in var_map:
            init_value = var_map[var]
            init_value = self.filter_conditon(init_value)
            init_invariants.append( f'({var} == {init_value})')
        
        init_invariant = '&&'.join(init_invariants)


        value = self.filter_conditon(value)
        cond = cond.replace('@last','')
        cond = self.filter_conditon(cond)


        def contains_no_letters(updated_loop_condition):
            # 检查字符串中是否含有字母
            if re.search(r'[a-zA-Z]', updated_loop_condition):
                return False  # 含有字母
            else:
                return True  # 不含字母

        if contains_no_letters(updated_loop_condition):
            if cond == '':
                invariant_annotation = f"loop invariant ({init_invariant}) || ({key} == {value}) ;"
            else:
                invariant_annotation = f"loop invariant ({init_invariant}) || ( ({cond})  ==> ({key} == {value}) ) ;"
        else:
            if cond == '':
                invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> ( ({init_invariant}) || ({key} == {value}) );"
            else:
                invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> ( ({init_invariant}) ||  ( ({cond})  ==> ({key} == {value}) ) );"
            
        
       
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




    def append_simple_annotations(self, annotations, var_map , updated_loop_condition, cond, key, value):
    
        invariant_annotation = ''


        init_invariants = []
        for var in var_map:
            init_value = var_map[var]
            init_value = self.filter_conditon(init_value)
            init_invariants.append( f'({var} == {init_value})')
        
        init_invariant = '&&'.join(init_invariants)


        value = self.filter_conditon(value)
        cond = self.filter_conditon(cond)


        def contains_no_letters(updated_loop_condition):
            # 检查字符串中是否含有字母
            if re.search(r'[a-zA-Z]', updated_loop_condition):
                return False  # 含有字母
            else:
                return True  # 不含字母

        if contains_no_letters(updated_loop_condition):
            if cond == '':
                invariant_annotation = f"loop invariant ({init_invariant}) || ({key} == {value}) ;"
            elif '@last' not in cond :
                invariant_annotation = f"loop invariant ({init_invariant}) || ( ({cond})  ==> ({key} == {value}) ) ;"
            else :
                invariant_annotation = f"loop invariant ({init_invariant}) || (PLACE_HOLDER_{key}) ;"
        else:
            if cond == '':
                invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> ( ({init_invariant}) || ({key} == {value}) );"
            elif '@last' not in cond :
                invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> ( ({init_invariant}) ||  ( ({cond})  ==> ({key} == {value}) ) );"
            else:
                invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> ( ({init_invariant}) || (PLACE_HOLDER_{key}) );"
            
    
                
       
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
    
    
    #def append_medium_annotations(self,annotations, var_map ,updated_loop_condition,key):
    def append_medium_annotations(self,annotations,var_map,updated_loop_condition,cond,key):
        
        init_invariants = []
        for var in var_map:
            init_value = var_map[var]
            init_value = self.filter_conditon(init_value)
            init_invariants.append( f'({var} == {init_value})')
        
        
        init_invariant = '&&'.join(init_invariants)

        def contains_no_letters(updated_loop_condition):
            # 检查字符串中是否含有字母
            if re.search(r'[a-zA-Z]', updated_loop_condition):
                return False  # 含有字母
            else:
                return True  # 不含字母

        
        # if contains_no_letters(updated_loop_condition):
        # # 未进入循环
        #     invariant_annotation= f"loop invariant  ( {init_invariant} ) || PLACE_HOLDER_{key} ;"
        # else:
        #     invariant_annotation= f"loop invariant ({updated_loop_condition}) ==> ( ( {init_invariant} ) || PLACE_HOLDER_{key} );"

        cond = self.filter_conditon(cond)



        if contains_no_letters(updated_loop_condition):
            if cond == '':
                invariant_annotation = f"loop invariant ({init_invariant}) || (PLACE_HOLDER_{key}) ;"
            elif '@last' not in cond :
                invariant_annotation = f"loop invariant ({init_invariant}) || ( ({cond})  ==> (PLACE_HOLDER_{key}) ) ;"
            else:
                invariant_annotation = f"loop invariant ({init_invariant}) || (PLACE_HOLDER_{key});"
        else:
            if cond == '':
                invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> ( ({init_invariant}) || (PLACE_HOLDER_{key}) );"
            elif '@last' not in cond :
                invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> ( ({init_invariant}) ||  ( ({cond})  ==> (PLACE_HOLDER_{key}) ) );"
            else:
                invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> ( ({init_invariant}) || (PLACE_HOLDER_{key}) );"




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
    
    #def append_hard_annotations(self,annotations, updated_loop_condition,key):
    def append_hard_annotations(self,annotations,updated_loop_condition,cond,key):

        
        def contains_no_letters(updated_loop_condition):
            # 检查字符串中是否含有字母
            if re.search(r'[a-zA-Z]', updated_loop_condition):
                return False  # 含有字母
            else:
                return True  # 不含字母
            
        # if contains_no_letters(updated_loop_condition):
        #     invariant_annotation= f"loop invariant PLACE_HOLDER_{key} ;"
        # else:
        #     invariant_annotation= f"loop invariant ({updated_loop_condition}) ==> ( PLACE_HOLDER_{key} );"

        
        cond = self.filter_conditon(cond)

        if contains_no_letters(updated_loop_condition):
            if cond == '':
                invariant_annotation = f"loop invariant PLACE_HOLDER_{key} ;"
            elif '@last' not in cond :
                invariant_annotation = f"loop invariant ({cond})  ==> (PLACE_HOLDER_{key})  ;"
            else:
                invariant_annotation = f"loop invariant PLACE_HOLDER_{key} ;"
        else:
            if cond == '':
                invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> (PLACE_HOLDER_{key});"
            elif '@last' not in cond :
                invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> ( ({cond})  ==> (PLACE_HOLDER_{key}) );"
            else:
                invariant_annotation = f"loop invariant ({updated_loop_condition}) ==> (PLACE_HOLDER_{key});"

        
        
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


    def solve_statemap(self,statemap):
        """
        输入: statemap 字典，格式如 {'x': 'x@last + y@last', 'y': 'y@last + 1'}
        输出: 包含所有 key@last 变量解的字典
        """
        # 提取所有当前变量名（如 'x', 'y'）
        current_vars = list(statemap.keys())
        
        # 从所有表达式中提取所有 @last 变量名（如 'x@last', 'y@last'）
        last_vars = set()
        pre_vars = set()
        for expr in statemap.values():
            last_matches = re.findall(r'\b([a-zA-Z_]\w*)@last\b', expr)
            last_vars.update(f"{m}@last" for m in last_matches)

            pre_matches = re.findall(r'\b([a-zA-Z_]\w*)@pre\b', expr)
            pre_vars.update(f"{m}@pre" for m in pre_matches)

        last_vars = list(last_vars)
        pre_vars = list(pre_vars)
        
        # 创建符号变量映射表
        # 1. 当前变量直接使用原名称（如 symbols('x'), symbols('y')）
        # 2. @last 变量将 @ 替换为 _ （如 'x@last' -> symbols('x_last')）
        symbol_map = {}
        for var in current_vars:
            symbol_map[var] = symbols(var)  # 当前变量符号
        for lvar in last_vars:
            safe_name = lvar.replace('@', '_')  # 合法符号名
            symbol_map[lvar] = symbols(safe_name)  # @last 变量符号
        for pvar in pre_vars:
            safe_name = pvar.replace('@', '_')  # 合法符号名
            symbol_map[pvar] = symbols(safe_name)  # @pre 变量符号
        
        # 构建方程组
        equations = []
        for key in statemap:
            expr_str = statemap[key]
            # 将表达式中的 @last 变量替换为符号变量（如 'x@last' -> x_last）
            parsed_expr = expr_str.replace('@', '_') 
            equations.append(Eq(symbol_map[key], sympify(parsed_expr)))  # 等式 key = expr
        
        # 提取所有 @last 变量的符号作为未知数
        unknowns = [symbol_map[lvar] for lvar in last_vars]
        
        # 解方程组
        solutions = solve(equations, unknowns, dict=True)
        if not solutions:
            return None
        
        # 将解转换为原始 @last 变量名的字典
        result = {}
        for lvar in last_vars :
            sym = symbol_map[lvar]
            ans = str(solutions[0].get(sym, None))

            for pvar in pre_vars:
                ans = ans.replace(str(symbol_map[pvar]),pvar)

            result[lvar] = ans
        
        return result

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
            model="deepseek-v3",
            messages=self.messages,
            temperature=0.7
        )

        # 处理响应
        assistant_response = response.choices[0].message.content
        # assistant_response = re.sub(r'<think>.*?</think>', '', assistant_response, flags=re.DOTALL)
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

        annotations  = self.append_notin_annotations(annotations,var_map,updated_loop_condition)

        for path in unloop_paths:
            states = path['state']
            cond = path['path_condition']
            state_map = self.extract_var_map_from_state(states)
            print(state_map)
            reverse_map = self.solve_statemap(state_map)
            print(reverse_map)

            if reverse_map != None:
                for key in reverse_map.keys():
                    value = reverse_map[key]
                    cond = cond.replace(key,value)
            


            for key in state_map.keys():
                if key not in unchanged_vars:
                    value = state_map[key]
                    if '@last' not in value and len(unloop_paths) == 1:
                        # 可以不反解
                        annotations  = self.append_special_annotations(annotations,var_map,updated_loop_condition,cond,key,value)
                    elif '@last' not in value :
                        # 非迭代关系
                        annotations  = self.append_simple_annotations(annotations,var_map,updated_loop_condition,cond,key,value)
                    elif f"{key}@last" not in value :
                        # annotations  = self.append_medium_annotations(annotations,var_map,updated_loop_condition,key)
                        annotations  = self.append_medium_annotations(annotations,var_map,updated_loop_condition,cond,key)
                    else :
                        # annotations  = self.append_hard_annotations(annotations,updated_loop_condition,key)
                        annotations  = self.append_hard_annotations(annotations,updated_loop_condition,cond,key)

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