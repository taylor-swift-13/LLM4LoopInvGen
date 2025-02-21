import subprocess
import argparse
import os
import re


class SyntaxChecker:
    def __init__(self):
        self.syntax_msg = ""  # 用于存储所有输出内容

    def delete_file_if_exists(self,file_path):
        """如果文件存在，则删除文件"""
        # 构建完整的文件路径
        file_path = os.path.join('../sac_c_parser/test', file_path)

        if os.path.exists(file_path):  # 检查文件是否存在
            os.remove(file_path)  # 删除文件
        

    # 设置命令行参数解析器
    def parse_args(self):
        parser = argparse.ArgumentParser(description="Run Frama-C WP on a C file.")
        parser.add_argument('file_name', help="Path to the C file to analyze")
        return parser.parse_args()


    def run(self, file_name=None):

        if file_name is None:
            # 如果没有传入 file_name，从命令行参数获取
            args = self.parse_args()
            file_name = args.file_name
            
        
        file_name = file_name.split('.')[0]

        

                # 定义文件路径
        goal_file = f"../ip_postcond/goal/{file_name}_goal.v"
        proof_auto_file = f"../ip_postcond/goal/{file_name}_proof_auto.v"
        proof_manual_file = f"../ip_postcond/goal/{file_name}_proof_manual.v"
        iter_file = f"../../LoopInvGen_V/output/{file_name}.c"

         # 检查文件是否存在，存在则删除
        for file_path in [goal_file, proof_auto_file, proof_manual_file]:
            self.delete_file_if_exists(file_path)

        command = [
                    "build/symexec",
                    f"--goal-file={goal_file}",
                    f"--proof-auto-file={proof_auto_file}",
                    f"--proof-manual-file={proof_manual_file}",
                    f"--input-file={iter_file}"
                ]

        try:
            result = subprocess.run(
                        command,
                        cwd='../sac_c_parser/test',
                        stdout=subprocess.PIPE,
                        stderr=subprocess.PIPE,
                        text=True
                )

            if re.search(r'error', result.stderr, re.IGNORECASE):  # 不分大小写，忽略中间空格
                print("syntax Error")
                
               # 去除包含 'LoopEntry' 的行及其下一行
                error_message = result.stderr
                lines = error_message.splitlines()
                filtered_lines = []
                skip_next = False
                
                for line in lines:
                    if skip_next:
                        skip_next = False
                        continue
                    if 'LoopEntry' in line:
                        skip_next = True
                        continue
                    filtered_lines.append(line)
                
                # 重新组合过滤后的行
                filtered_error_message = '\n'.join(filtered_lines)
                print(filtered_error_message)

                self.syntax_msg = filtered_error_message
                return False
           

            else:
                print("syntax Correct")  
                return True  
            
        except subprocess.CalledProcessError as e:
            print("syntax Error")

            return False

        
            
if __name__ == "__main__":
    checker = SyntaxChecker()
    checker.run()