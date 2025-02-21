import os
from syntaxChecker import SyntaxChecker
from yangfp.LLM4LoopInvGen.invGen import InvGenerator
from yangfp.LLM4LoopInvGen.invMod import InvModifier

def print_statistics(syntax_count,file_count, error_files):
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
    print("-" * 40)

    if error_files:
        print("错误的文件名:")
        for error_file in error_files:
            print(f"  - {error_file}")
    else:
        print("所有文件验证通过，没有错误文件。")
    print("=" * 40)

def main():


    # 指定要遍历的文件夹路径
    input_folder = 'input'

    # 统计合法文件个数
    syntax_count = 0
    file_count = 0
    error_files = []

    # 初始化语法检查器
    checker = SyntaxChecker()

    # 遍历文件夹中的所有文件
    # for filename in os.listdir(input_folder):
    #     if filename.endswith('.c'):  # 只处理 .c 文件
    #         file_count += 1
    #         # 运行语法检查

    #         if checker.run(filename):
    #             syntax_count += 1
    #         else:
    #             print(f"{filename} fails : {checker.syntax_msg}")
    #             error_files.append(filename)

    # 遍历文件夹中的所有文件
    for filename in os.listdir(input_folder):
        if filename.endswith('.c'):  # 只处理 .c 文件
            file_count += 1

            # 尝试三次语法检查
            success = False
            for attempt in range(3):  # 最多尝试三次

                # 运行不变式生成器
                generator = InvGenerator()
                generator.run(filename)

                # 运行语法检查
                if checker.run(filename):
                    success = True
                    syntax_count += 1
                    break  # 如果通过，跳出尝试循环
                else:
                    error_message = checker.syntax_msg
                    modifier = InvModifier(filename,error_message)
                    modifier.run()
                    if checker.run(filename):
                        success = True
                        syntax_count += 1
                        break  # 如果通过，跳出尝试循环

            # 如果三次尝试都失败，记录错误信息
            if not success:
                error_files.append(filename)
                


    # 打印统计信息
    print_statistics(syntax_count, file_count, error_files)


if __name__ == "__main__":
    main()

         
