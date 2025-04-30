import json
import re
import openai
class LoopAnalysis:
    def __init__(self,json_file,idx):
        """
        :param json_file: JSON 文件路径或数据
        :param idx: 需要提取的循环索引
        """
        self.json_file = json_file
        self.idx = idx
        self.pre_condition =None
        self.path_conds = None
        self.loop_condition = None
        self.updated_loop_conditions = None
        self.var_maps = None
        self.global_unchanged_vars = None
        


        # OpenAI 客户端初始化
        self.client = openai.OpenAI(
            base_url="https://yunwu.ai/v1",
            api_key="sk-KBkzvVT2JoKyUhmd0f4tkpCKXQNuSBMJpInHMFTnkKDI6zAA"
        )
        # 初始化消息列表
        self.messages = [
            {"role": "system", "content": "You are a helpful assistant."}
        
        ]
    def filter_conditon(self,condition):
        return re.sub(r'(\w+)@pre', r'\\at(\1, Pre)', condition)
    


    def get_json_at_index(self):
        with open(self.json_file, 'r') as file:
            data = json.load(file)  # 读取并解析 JSON 文件
            
            if isinstance(data, list) and 0 <= self.idx < len(data):
                return data[self.idx]  # 返回第 idx 个 JSON 对象
            else:
                raise IndexError("Index out of range or data is not a list")
            
    

    def extract_precond_from_file(self):
        
        loop = self.get_json_at_index()  # 获取指定索引的循环数据
        condition = loop.get("condition", "")  # 获取条件表达式
        return condition
    
    def extract_unchanged_vars(self):
        
        loop = self.get_json_at_index()  # 获取指定索引的循环数据
        loop_content = loop.get("content", "")  # 获取循环内容
        var_map = self.var_maps[0]  # 获取变量映射表（字典）

        unchanged_vars = []  # 用于存储未改变的变量

        # 遍历 var_map 中的键（变量名）
        for var_name in var_map.keys():
            # 使用正则表达式检查变量是否在循环内容中作为左值出现
            # 匹配模式：变量名 + 可能的空格 + = （排除 ==）
            # pattern = re.compile(rf"\b{var_name}\s*(\+=|-=|\*=|/=|=)(?!=)")
            pattern = re.compile(
            rf"(\b{var_name}\b\s*(\+\+|--|\+=|-=|\*=|/=|=(?!=))|(\+\+|--)\s*\b{var_name}\b)"
        )
            if not pattern.search(loop_content):
                unchanged_vars.append(var_name)

        return unchanged_vars


    def extract_var_map_from_file(self):
        loop = self.get_json_at_index()  # 获取指定索引的循环数据
        condition = loop.get("condition", "")  # 获取条件表达式

        # 根据 || 分割条件表达式
        sub_conditions = [s.strip() for s in condition.split("||")]

        # 存储所有 var_map 的列表
        var_maps = []
        path_conds = []

        def split_path_and_state(expression):
            """
            按最后一个 && 分割字符串，得到 path 和 state
            :param expression: 输入的表达式字符串
            :return: 返回 path 和 state 两部分
            """
            # 查找最后一个 && 的位置
            last_and_index = expression.rfind("&&")

            if last_and_index == -1:
                # 如果没有找到 &&，path 为空，整个表达式作为 state
                path = None
                state = expression.strip()
            else:
                # 按最后一个 && 分割
                path = expression[:last_and_index].strip()
                if 'exists' in path:
                    path = None
                state = expression[last_and_index + 2:].strip()

            return path, state

        # 正则表达式匹配形如 "var == value" 的部分，支持嵌套括号


        def parse_expressions(s):
            var_map = {}
            remaining = s.strip()
            stack = []
            expr_start = 0
            i = 0
            n = len(remaining)
            
            while i < n:
                char = remaining[i]
                
                # 处理括号层级
                if char == '(':
                    stack.append(i)
                elif char == ')':
                    if stack:
                        stack.pop()
                
                # 遇到逻辑运算符且不在括号内时，分割表达式
                if i < n-1 and remaining[i:i+2] in ('&&', '* ') and not stack:
                    # 提取当前表达式
                    expr = remaining[expr_start:i].strip()
                    # 解析表达式中的键值对
                    eq_pos = expr.find('==')
                    if eq_pos != -1:
                        var = expr[:eq_pos].strip(' ()')
                        value = expr[eq_pos+2:].strip(' ()')
                        var_map[var] = value
                    expr_start = i + 2
                    i += 1  # 跳过运算符的第二个字符
                
                i += 1
            
            # 处理最后一个表达式
            expr = remaining[expr_start:].strip()
            eq_pos = expr.find('==')
            if eq_pos != -1:
                var = expr[:eq_pos].strip(' ()')
                value = expr[eq_pos+2:].strip(' ()')
                var_map[var] = value
                
            return var_map

        for sub_condition in sub_conditions:

            path,state = split_path_and_state(sub_condition)
            var_map = {}  # 为每个子条件创建一个新的 var_map
            path_cond = path
            path_conds.append(path_cond)
           
            var_map = parse_expressions(state)

            var_maps.append(var_map)  # 将 var_map 添加到列表中

        return var_maps,path_conds
    
    def extract_first_loop_condition(self):
       
        loop = self.get_json_at_index()
        code = loop.get("content", "")
        
        # 查找第一个出现的 for 或 while 关键字
        loop_keywords = ["for", "while"]
        first_pos = len(code)
        keyword_found = None
        for keyword in loop_keywords:
            pos = code.find(keyword)
            if pos != -1 and pos < first_pos:
                first_pos = pos
                keyword_found = keyword
        if keyword_found is None:
            return None  # 未找到循环关键字
        
        # 确保找到的是完整的关键字
        if (first_pos > 0 and (code[first_pos-1].isalnum() or code[first_pos-1]=='_')) or \
        (first_pos + len(keyword_found) < len(code) and (code[first_pos+len(keyword_found)].isalnum() or code[first_pos+len(keyword_found)]=='_')):
            return None
        
        # 定位 '('（跳过关键字和空格）
        cursor = first_pos + len(keyword_found)
        while cursor < len(code) and code[cursor].isspace():
            cursor += 1
        if cursor >= len(code) or code[cursor] != '(':
            return None  # 没有找到左括号
        cursor += 1  # 跳过 '('
        
        # 提取括号内的内容，支持括号嵌套
        condition_start = cursor
        paren_depth = 1
        while cursor < len(code) and paren_depth > 0:
            if code[cursor] == '(':
                paren_depth += 1
            elif code[cursor] == ')':
                paren_depth -= 1
            cursor += 1
        if paren_depth != 0:
            return None  # 括号不匹配
        inner = code[condition_start: cursor-1].strip()
        
        # 提取条件
        condition = None
        if keyword_found == "while":
            # while 循环条件为整个括号内内容
            condition = inner
        elif keyword_found == "for":
            # for 循环通常包含三个表达式：初始化; 条件; 迭代，条件在中间
            parts = []
            part = ""
            nested = 0  # 处理内部括号嵌套
            for ch in inner:
                if ch == '(':
                    nested += 1
                elif ch == ')':
                    nested -= 1
                if ch == ';' and nested == 0:
                    parts.append(part.strip())
                    part = ""
                else:
                    part += ch
            parts.append(part.strip())
            # 条件部分位于第二个分号分隔部分（若存在）
            if len(parts) >= 2:
                condition = parts[1]
            else:
                condition = None

            if condition == '':
                condition = None
        return condition

    


    def replace_vars_with_values(self, loop_cond, var_maps):
        
        updated_loop_conditions = []

        if loop_cond == None:
            return [None]

        for var_map in var_maps:
            # 将字符串转换为列表，方便修改
            loop_cond_list = list(loop_cond)
            i = 0  # 当前查找位置

            while i < len(loop_cond_list):
                # 从左到右查找变量名
                for var in var_map:
                    # 检查当前位置是否匹配变量名
                    if loop_cond_list[i:i + len(var)] == list(var):
                        # 检查变量名是否完整（前后是单词边界或非字母数字字符）
                        is_start_boundary = (i == 0 or not loop_cond_list[i - 1].isalnum())
                        is_end_boundary = (i + len(var) >= len(loop_cond_list) or not loop_cond_list[i + len(var)].isalnum())
                        if is_start_boundary and is_end_boundary:
                            # 替换变量名
                            loop_cond_list[i:i + len(var)] = list(var_map[var])
                            # 跳过替换后的部分
                            i += len(var_map[var]) - 1
                            break
                i += 1

            # 将列表转换回字符串并添加到结果中
            updated_loop_conditions.append(''.join(loop_cond_list))

        return updated_loop_conditions
    



    def run(self):

        # 提取变量映射
        var_maps,path_conds = self.extract_var_map_from_file()
        self.var_maps =var_maps
        self.path_conds = path_conds
        print("Variable Maps:", var_maps)
        print("Path conditions:", path_conds)
    

        # 提取前置条件
        pre_condition = self.extract_precond_from_file()
        self.pre_condition =pre_condition
        print("Pre condition:", pre_condition)

        # 提取循环条件
        loop_condition = self.extract_first_loop_condition()
        self.loop_condition = loop_condition
        print("Loop Condition:", loop_condition)

        # 替换循环条件中的变量为值
        if var_maps :
            updated_loop_conditions = self.replace_vars_with_values(loop_condition, var_maps)
            self.updated_loop_conditions = updated_loop_conditions
            print("Updated Loop Conditions:", updated_loop_conditions)

        global_unchanged_vars = self.extract_unchanged_vars()
        self.global_unchanged_vars = global_unchanged_vars 
        print("Global Unchanged Variables", global_unchanged_vars)






# 示例调用 
if __name__ == "__main__":
   
   json_file = 'loop/09.json'
   idx = 0
   analyzer= LoopAnalysis(json_file,idx)
   analyzer.run()