import os
import sys
import shutil
import time
from outputVerify import OutputVerifier
from invGen import InvGenerator
from datetime import datetime

class DualOutput:
    """同时输出到控制台和文件的类"""
    def __init__(self, terminal, file):
        self.terminal = terminal
        self.file = file
    
    def write(self, message):
        self.terminal.write(message)
        self.file.write(message)
        self.flush()
    
    def flush(self):
        self.terminal.flush()
        self.file.flush()

def move_processed_files(source_folder, dest_folder, file):
    """将处理过的文件移动到目标文件夹"""
    os.makedirs(dest_folder, exist_ok=True)
    src_path = os.path.join(source_folder, file)
    dest_path = os.path.join(dest_folder, file)
    try:
        shutil.move(src_path, dest_path)
        print(f"已移动文件: {file} -> {dest_folder}")
    except Exception as e:
        print(f"移动文件 {file} 失败: {str(e)}")

def main():

    # 创建日志文件
    log_filename = f"result/output_{datetime.now().strftime('%Y%m%d_%H%M%S')}.txt"
    log_file = open(log_filename, 'w', encoding='utf-8')
    
    # 备份原始stdout
    original_stdout = sys.stdout
    
    try:
        # 设置双重输出
        sys.stdout = DualOutput(original_stdout, log_file)
        
        # 以下是您原有的代码，完全保持不变
        input_folder = 'input'

        valid_count_5 = 0
        correct_count_5 = 0
        syntax_count_5 =0

        valid_count_1=0
        correct_count_1 = 0
        syntax_count_1 =0

        valid_count_3 =0
        correct_count_3 = 0
        syntax_count_3 =0

        file_count = 133

        correct_files_1 = []
        correct_files_3 = []
        correct_files_5 = []

        error_files_1 = []
        error_files_3 = []
        error_files_5 = []

        finshed_files = []

        start_time = time.time()

        for root, dirs, files in os.walk(input_folder):
            for file in files:

                file_start_time = time.time()

                
                print(f"finshed_files:{finshed_files}")
                print(f"file:{file}")
                print('pass@1')
                print(f"合法个数：{syntax_count_1}/{file_count}")
                print(f"合法率： {(syntax_count_1 / file_count) * 100:.2f}%")
                print(f"有效个数：{valid_count_1}/{file_count}")
                print(f"有效率： {(valid_count_1 / file_count) * 100:.2f}%")
                print(f"正确个数: {correct_count_1}/{file_count}")
                print(f"正确率: {(correct_count_1 / file_count) * 100:.2f}%")
                print(f"正确文件:{correct_files_1}")
                print(f"错误文件：{error_files_1}")
                print('------------------------------------------------------------')
                print('pass@3')
                print(f"合法个数：{syntax_count_3}/{file_count}")
                print(f"合法率： {(syntax_count_3 / file_count) * 100:.2f}%")
                print(f"有效个数：{valid_count_3}/{file_count}")
                print(f"有效率： {(valid_count_3 / file_count) * 100:.2f}%")
                print(f"正确个数: {correct_count_3}/{file_count}")
                print(f"正确率: {(correct_count_3 / file_count) * 100:.2f}%")
                print(f"正确文件:{correct_files_3}")
                print(f"错误文件：{error_files_3}")
                print('------------------------------------------------------------')
                print('pass@5')
                print(f"合法个数：{syntax_count_5}/{file_count}")
                print(f"合法率： {(syntax_count_5 / file_count) * 100:.2f}%")
                print(f"有效个数：{valid_count_5}/{file_count}")
                print(f"有效率： {(valid_count_5 / file_count) * 100:.2f}%")
                print(f"正确个数: {correct_count_5}/{file_count}")
                print(f"正确率: {(correct_count_5 / file_count) * 100:.2f}%")
                print(f"正确文件:{correct_files_5}")
                print(f"错误文件：{error_files_5}")

                flag = False
                flag1 = False
                flag3 = False
                
                isValid = False
                isSyntax = False

                isValid3 =False
                isSyntax3=False

                for t in range(5):
                    generator = InvGenerator()
                    generator.run(file)

                    verifier = OutputVerifier()
                    verifier.run(file)

                    validate_result = verifier.validate_result
                    verify_result = verifier.verify_result
                    syntax_error = verifier.syntax_error

                    valid = bool(validate_result) and all(validate_result)
                    syntax = syntax_error ==''
                    satisfy = bool(verify_result) and all(verify_result)

                    if syntax and not isSyntax:

                        if t == 0 :
                            syntax_count_1  += 1

                        if t <= 2 and not isSyntax3:
                            syntax_count_3  += 1
                            isSyntax3 =True

                        syntax_count_5 += 1
                        isSyntax = True

                    if valid and not isValid:
                        if t == 0 :
                            valid_count_1  += 1

                        if t <= 2 and not isValid3:
                            valid_count_3  += 1
                            isValid3 = True
                        
                        valid_count_5 += 1
                        isValid = True

                    if valid and satisfy:
                        if t == 0 :
                            correct_count_1  += 1
                            correct_files_1.append(file)
                            flag1 = True

                        if t <= 2:
                            correct_count_3  += 1
                            correct_files_3.append(file)
                            flag3 = True
                            
                        correct_count_5 += 1
                        correct_files_5.append(file)
                        flag = True
                        break

                if not flag1:
                    error_files_1.append(file)

                if not flag3:
                    error_files_3.append(file)

                if not flag:
                    error_files_5.append(file)

                move_processed_files('input','finish',file)
                
                finshed_files.append(file)
                print('-----------------------------------------')

                file_time = time.time() - file_start_time
                print(f"\n文件 {file} 处理完成. 总耗时: {(file_time)}")
                print('-----------------------------------------')

        total_time = time.time() - start_time

        print(f"总耗时：{total_time}")
        print(f"平均用时：{(total_time/file_count)}")
        print_statistics(syntax_count_1, valid_count_1, correct_count_1, file_count, error_files_1)
        print_statistics(syntax_count_3, valid_count_3, correct_count_3, file_count, error_files_3)
        print_statistics(syntax_count_5, valid_count_5, correct_count_5, file_count, error_files_5)
        
    finally:
        # 恢复原始stdout并关闭文件
        sys.stdout = original_stdout
        log_file.close()
        print(f"\n所有输出已保存到: {log_filename}")

def print_statistics(syntax_count,valid_count,correct_count, file_count, error_files):
    """
    打印统计信息，包括正确个数、文件总数、正确率以及错误的文件名
    :param correct_count: 正确个数
    :param file_count: 文件总数
    :param error_files: 错误的文件名列表
    """
    # 打印统计信息
    print("=" * 40)
    print(f"{'统计结果':^40}")  # 居中显示标题
    print("=" * 40)
    print(f"合法个数：{syntax_count}/{file_count}")
    print(f"合法率： {(syntax_count / file_count) * 100:.2f}%")
    print(f"有效个数：{valid_count}/{file_count}")
    print(f"有效率： {(valid_count / file_count) * 100:.2f}%")
    print(f"正确个数: {correct_count}/{file_count}")
    print(f"正确率: {(correct_count / file_count) * 100:.2f}%")
    print("-" * 40)

    if error_files:
        print("错误的文件名:")
        for error_file in error_files:
            print(f"  - {error_file}")
    else:
        print("所有文件验证通过，没有错误文件。")
    print("=" * 40)

if __name__ == "__main__":
    main()