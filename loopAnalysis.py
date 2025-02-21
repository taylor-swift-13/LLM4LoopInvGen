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
        self.loop_condition = None
        self.updated_loop_condition = None
        self.unchanged_vars = None
        self.var_map = None
        self.result = None
        # OpenAI 客户端初始化
        self.client = openai.OpenAI(
            base_url="https://yunwu.ai/v1",
            api_key="sk-S3fNVvxTTDcQymGTYJU35ZheQZ6cON1zZW0rMGeM8F1nIA6l"
        )
        # 初始化消息列表
        self.messages = [
            {"role": "system", "content": "You are a helpful assistant."}
        
        ]    


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
        pattern = r'(\w+)\s*==\s*(\([^()]*\)|[^()]+)'
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
    

    
    def run(self):
         # 创建 LoopCondGenerator 实例

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
            #print(updated_loop_condition)
            print("Updated Loop Condition:", updated_loop_condition)

        unchanged_vars = self.extract_unchanged_vars()
        self.unchanged_vars = unchanged_vars  
        print("Unchanged Vars:" ,unchanged_vars)


    



# 示例调用 
if __name__ == "__main__":
   json_file = 'loop/loop_19.json'
   idx = 0
   analysis = LoopAnalysis(json_file,idx)
   analysis.run()