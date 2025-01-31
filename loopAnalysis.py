import json
import re
import openai
from iterAnalysis import IterationAnalysis

class LoopAnalysis:
    def __init__(self,json_file,idx):
        """
        :param json_file: JSON 文件路径或数据
        :param idx: 需要提取的循环索引
        """
        self.json_file = json_file
        self.idx = idx
        self.pre_condition =None
        self.loop_condition = None
        self.updated_loop_condition = None
        self.var_map = None
        self.unchanged_vars = None
        self.unloop_name =None
        self.unloop_paths = None


        # OpenAI 客户端初始化
        self.client = openai.OpenAI(
            base_url="https://yunwu.ai/v1",
            api_key="sk-KBkzvVT2JoKyUhmd0f4tkpCKXQNuSBMJpInHMFTnkKDI6zAA"
        )
        # 初始化消息列表
        self.messages = [
            {"role": "system", "content": "You are a helpful assistant."}
        
        ]
    
    def replace_pre_with_last(self, state, path_condition):
        """将不在 unchanged_vars 中的变量的 v@pre 替换为 v@last"""
    
        def replace_match(match):
            """替换每个匹配的 v@pre 为 v@last，如果变量不在 unchanged_vars 中"""
            key_with_suffix = match.group(0)  # 获取匹配的 v@pre
            key = key_with_suffix[:-4]  # 移除 "@pre" 后缀，获取原 key
            
            # 如果 key 不在 unchanged_vars 中，替换为 v@last，否则保持 v@pre
            if key not in self.unchanged_vars:
                return key + '@last'
            else:
                return key_with_suffix  # 不修改
        
        # 正则表达式匹配所有的 v@pre 格式
        pattern = r'\b([a-zA-Z_]\w*)@pre\b'
        
        # 对 state 和 path_condition 分别执行替换
        state_replaced = re.sub(pattern, replace_match, state)
        path_condition_replaced = re.sub(pattern, replace_match, path_condition)
        
        return state_replaced, path_condition_replaced
    
    def load_iter_json(self,file_path):
        """读取 JSON 文件并提取每一条路径以及对应的状态"""
        with open(file_path, 'r', encoding='utf-8') as f:
            data = json.load(f)  # 加载 JSON 数据

        # 使用字典或列表组织每一条路径及其对应的状态
        path_state_pairs = []


        for item in data:
            state = item['state']  # 提取状态
            path_condition = item['path_condition']  # 提取路径条件

            # 替换 state 和 path_condition 中不在 unchanged_vars 中的变量 v@pre 为 v@last
            state, path_condition = self.replace_pre_with_last(state, path_condition)
   
            
            # 将每条路径和对应的状态作为元组，添加到列表中
            path_state_pairs.append({
                "state": state,
                "path_condition": path_condition
            })

        return path_state_pairs

    def get_unloop_name(self):
        return self.unloop_name

    # 寻找每个 循环 开头和结尾的地方
    def unloop_content(self):
        vars = self.var_map.keys()

        int_params = ", ".join([f" int {var} " for var in vars])

         # 拼接函数签名
        function_signature = f"void poo({int_params})"

        vst_annotations = '''
        /*@
            Require emp
            Ensure emp
        */
        '''
        # 将代码拆分成单字符的列表
        
        loop = self.get_json_at_index()  # 获取指定索引的循环数据
        code = loop.get("content", "")  # 获取条件表达式
        code = re.sub(r'/\*[^@]*@.*?\*/', '', code, flags=re.DOTALL)
        code_list = list(code)
        ridx = self.idx
        
        # 查找所有的 for 或 while 循环位置
        loop_pattern = r'\b(for|while)\s*\((.*?)\)\s*{'
        matches = list(re.finditer(loop_pattern, code))
        
        
        # 处理每一个循环
        for idx, match in enumerate(matches):
            # 循环的起始位置
            if idx == ridx:
                loop_start = match.start()  
                begin_idx = loop_start

                while True:
                    if code_list[begin_idx] == '{':
                        break
                    else:
                        begin_idx +=1

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

        code_list[end_index-1] = f'/*@ Print user assertion at number End*/ \n }}'
        
        unloop = function_signature + vst_annotations + ''.join(code_list[begin_idx:end_index])

        file_name = f"{self.json_file.split('/')[1].split('.')[0]}_{self.idx}.c"

        self.unloop_name = file_name.split('.')[0]
        
        file_path = f'unloop/{file_name}'


        try:
            with open(file_path, "w") as file:
                file.write(unloop)
            print(f"内容已成功保存到：{file_path}")
        except Exception as e:
            print(f"保存文件时出错：{e}")

        return unloop


    def get_json_at_index(self):
        with open(self.json_file, 'r') as file:
            data = json.load(file)  # 读取并解析 JSON 文件
            
            if isinstance(data, list) and 0 <= self.idx < len(data):
                return data[self.idx]  # 返回第 idx 个 JSON 对象
            else:
                raise IndexError("Index out of range or data is not a list")

    def extract_precond_from_file(self):
        """
        从指定的 JSON 文件中读取数据，并提取前置条件。
        
        :param json_file: JSON 文件路径或数据
        :param idx: 需要提取的循环索引
        :return: 前置条件（字符串）
        """
        loop = self.get_json_at_index()  # 获取指定索引的循环数据
        condition = loop.get("condition", "")  # 获取条件表达式
        return condition
    
    def extract_unchanged_vars(self):
        """
        获得不变的变量
        """
        loop = self.get_json_at_index()  # 获取指定索引的循环数据
        loop_content = loop.get("content", "")  # 获取循环内容
        var_map = self.var_map  # 获取变量映射表（字典）

        unchanged_vars = []  # 用于存储未改变的变量

        # 遍历 var_map 中的键（变量名）
        for var_name in var_map.keys():
            # 使用正则表达式检查变量是否在循环内容中作为左值出现
            # 匹配模式：变量名 + 可能的空格 + = （排除 ==）
            pattern = re.compile(rf"\b{var_name}\s*(\+=|-=|\*=|/=|=)(?!=)")
            if not pattern.search(loop_content):
                unchanged_vars.append(var_name)

        return unchanged_vars

    def extract_var_map_from_file(self):
        """
        从指定的 JSON 文件中读取数据，并提取变量及其在 condition 中的赋值对应的映射（var_map）。
        
        :param json_file: JSON 文件路径或数据
        :param idx: 需要提取的循环索引
        :return: 变量及其赋值对应的映射（字典）
        """
        var_map = {}
        loop = self.get_json_at_index()  # 获取指定索引的循环数据
        condition = loop.get("condition", "")  # 获取条件表达式

        # 正则表达式匹配形如 "var == value" 的部分，支持嵌套括号
        pattern = r'(\w+)\s*==\s*(\((?:[^()]*|\((?:[^()]*|\([^()]*\))*\))*\)|[^()]+)'
        matches = re.findall(pattern, condition)

        for var, value in matches:
            # 去掉 value 中的外层括号（如果存在）
            value = value.strip()
            if value.startswith('(') and value.endswith(')'):
                value = value[1:-1]
            var_map[var] = value

        return var_map
    

    def extract_first_loop_condition(self):
        """
        从输入的代码中提取第一个 for 或 while 循环的条件。

        :param json_file: JSON 文件路径或数据
        :param idx: 需要提取的循环索引
        :return: 第一个循环条件（字符串），如果未找到则返回 None
        """

        loop = self.get_json_at_index()  # 获取指定索引的循环数据
        loop_content = loop.get("content", "")  # 获取循环内容

        # 正则表达式匹配 for 或 while 循环的条件
        pattern = r'(?:for|while)\s*\((.*?)\)'
        match = re.search(pattern, loop_content)
        
        if match:
            self.loop_condition = match.group(1)
            return match.group(1)  # 返回第一个匹配的条件部分
        return None  # 如果未找到，返回 None

    def replace_vars_with_values(self, loop_cond, var_map):
        """
        将循环条件中的变量替换为它们的值，确保每个位置只替换一次，从左到右查找并替换。

        :param loop_cond: 循环条件（字符串）
        :param var_map: 变量及其值的映射（字典）
        :return: 替换后的循环条件（字符串）
        """
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

        # 将列表转换回字符串
        return ''.join(loop_cond_list)
    

    def run(self):

        # 提取变量映射
        var_map = self.extract_var_map_from_file()
        self.var_map =var_map
        print("Variable Map:", var_map)
    

        # 提取前置条件
        pre_condition = self.extract_precond_from_file()
        self.pre_condition =pre_condition
        print("Pre condition:", pre_condition)

        # 提取循环条件
        loop_condition = self.extract_first_loop_condition()
        self.loop_condition = loop_condition
        print("Loop Condition:", loop_condition)

        # 替换循环条件中的变量为值
        if var_map and loop_condition:
            updated_loop_condition = self.replace_vars_with_values(loop_condition, var_map)
            self.updated_loop_condition = updated_loop_condition
            print(updated_loop_condition)
            print("Updated Loop Condition:", updated_loop_condition)

        unchanged_vars = self.extract_unchanged_vars()
        self.unchanged_vars = unchanged_vars  
        print(unchanged_vars)


        unloop = self.unloop_content()
        print(unloop)

        iter_json_file = f"iteration/{self.unloop_name}.json"

        iterAnalyzer = IterationAnalysis(self.unloop_name)
        iterAnalyzer.run()

        unloop_paths = self.load_iter_json(iter_json_file)
        self.unloop_paths =unloop_paths
        print(unloop_paths)
        
        
            







    

# 示例调用 
if __name__ == "__main__":
   json_file = 'loop/loop_3.json'
   idx = 0
   analyzer= LoopAnalysis(json_file,idx)
   analyzer.run()