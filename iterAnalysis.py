import argparse
import subprocess
import os
import json
import re

class IterationAnalysis:
    def __init__(self, file_name):
        """初始化文件路径和文件名"""
        self.file_name = file_name.split('.')[0]  # 去掉文件扩展名
        self.goal_file = f"../ip_postcond/goal/{self.file_name}_goal.v"
        self.proof_auto_file = f"../ip_postcond/goal/{self.file_name}_proof_auto.v"
        self.proof_manual_file = f"../ip_postcond/goal/{self.file_name}_proof_manual.v"
        self.json_file = f"iteration/{self.file_name}.json"
        self.input_file = f"../../LoopInvGen_V1/unloop/{self.file_name}.c"

    def delete_file_if_exists(self, file_path):
        """
        如果文件存在，则删除文件。
        :param file_path: 文件路径
        """
        file_path = os.path.join('../sac_c_parser/test', file_path)
        if os.path.exists(file_path):
            print(f"File found: {file_path}. Deleting the file.")
            os.remove(file_path)
        else:
            print(f"File not found: {file_path}. No file to delete.")

    def get_loop_end(self, text):
        """
        使用正则表达式从文本中提取第一个 LoopEntry_X 的条件。
        :param text: 输入的文本
        :return: 提取的循环条件
        """
        # 正则表达式匹配第一个 End_X: 后跟条件部分
        pattern = r"End:.*\n([^\n]*)"  # 只匹配条件部分，不提取 loop_id
        
        match = re.search(pattern, text)  # 使用 re.search 只匹配第一个
        if match:
            condition = match.group(1).strip()  # 提取条件并去掉首尾空白
            return condition
        else:
            return None  # 如果没有匹配项，返回 None
        
    def fix_parentheses(self,expression):
        """
        修复表达式中的括号匹配问题。如果括号不匹配，尝试修复。
        :param expression: 输入的条件字符串
        :return: 修复后的条件字符串，括号数目合法
        """
        balance = 0
        for char in expression:
            if char == '(':
                balance += 1
            elif char == ')':
                balance -= 1

        # 如果 balance > 0，说明有多余的左括号，补充右括号
        if balance > 0:
            expression += ')' * balance
        # 如果 balance < 0，说明有多余的右括号，去除多余的右括号
        elif balance < 0:
            expression = '(' * (-balance) + expression

        while expression.startswith('(') and expression.endswith(')') and expression[1:-1].startswith('(') and expression[1:-1].endswith(')')  :
        # 需要判断括号内部是否匹配合法，避免去掉无效的括号

            expression = expression[1:-1]

        return '(' + expression + ')'

    def process_conditions(self,line):
        """
        处理 lines 中的条件，提取并过滤合法的括号，修复不匹配的括号。
        :param lines: 包含条件的文本行列表
        :return: 处理后的 state 和 path_condition
        """
        # 处理 state，直接取最后一个条件
        state = line.split("&&")[-1]
        state = self.fix_parentheses(state.strip())

        # 处理 path_condition，修复每个条件中的括号
        path_conditions = []
        for condition in line.split("&&")[:-1]:
            condition = condition.strip()
            fixed_condition = self.fix_parentheses(condition)  # 修复括号
            path_conditions.append(fixed_condition)

        path_condition =' ==> '.join(path_conditions)
        return state, path_condition
        
    def save_to_json(self, output_file, text):
        """将数据写入 JSON 文件"""
        # 获取循环结束条件（调用之前定义的 get_loop_end 方法）
        data = self.get_loop_end(text)
        
        # 处理数据并生成包含递增 id 的 JSON 格式
        output = []
        
        # 分割每个条目为 return_value 和 path_condition
        lines = data.split("||")
        
        # 遍历每一行数据
        for idx, line in enumerate(lines):
            line = line.strip()  # 去掉前后空格
            
            if not line:
                continue  # 如果行为空，则跳过
            
            # 使用现有的方法处理每个条件行
            state, path_condition = self.process_conditions(line)
            
            # 为每个条目分配递增的 ID
            item = {
                "id": idx + 1,  # 使用递增的数字作为 id，从 1 开始
                "state": state,
                "path_condition": path_condition
            }
            output.append(item)

        # 将结果写入指定的 JSON 文件
        with open(output_file, 'w', encoding='utf-8') as f:
            json.dump(output, f, indent=4, ensure_ascii=False)
            print(f"Saved {output_file}")

    def run(self):
        """执行 symexec 命令并处理输出"""
        # 检查文件是否存在，存在则删除
        for file_path in [self.goal_file, self.proof_auto_file, self.proof_manual_file]:
            self.delete_file_if_exists(file_path)
        
        # 定义命令和参数
        command = [
            "build/symexec",
            f"--goal-file={self.goal_file}",
            f"--proof-auto-file={self.proof_auto_file}",
            f"--proof-manual-file={self.proof_manual_file}",
            f"--input-file={self.input_file}"
        ]

        # 运行命令，捕获输出
        try:
            result = subprocess.run(command, cwd='../sac_c_parser/test', stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

            if result.stderr:
                print("Error Output:")
                print(result.stderr)
                output = result.stderr
                self.save_to_json(self.json_file, output)
        
        except Exception as e:
            print(f"An error occurred: {e}")

def main():
    # 创建解析器
    parser = argparse.ArgumentParser(description="Read file_name from command-line arguments.")

    # 添加一个必需的参数 file_name
    parser.add_argument('file_name', type=str, help="The name of the file without extension")

    # 解析参数
    args = parser.parse_args()

   
    analyzer = IterationAnalysis(args.file_name)
    analyzer.run()

if __name__ == "__main__":
    main()
