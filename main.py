import os
from outputVerify import OutputVerifier
from invGen import InvGenerator

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

def main():
    # 指定要遍历的文件夹路径
    input_folder = 'input'

    # 统计正确个数

    valid_count = 0
    correct_count = 0
    syntax_count =0
    file_count = 65
    error_files = []

    for root, dirs, files in os.walk(input_folder):
        for file in files:

            flag = False
            isValid = False
            isSyntax = False

            # 尝试最多3次验证
            for _ in range(3):
                # 每次尝试都创建新的生成器和验证器
                generator = InvGenerator()
                generator.run(file)  # 传入完整路径

                verifier = OutputVerifier()
                verifier.run(file)   # 传入完整路径

                # 获取验证结果（假设返回的是列表）
                validate_result = verifier.validate_result
                verify_result = verifier.verify_result
                syntax_error = verifier.syntax_error

                # 判断验证结果
                valid = bool(validate_result) and all(validate_result)
                syntax = syntax_error ==''
                satisfy = bool(verify_result) and all(verify_result)

                if syntax and not isSyntax:
                    syntax_count += 1
                    isSyntax = True  # 修正赋值操作

                # 更新有效计数（每个文件只计一次）
                if valid and not isValid:
                    valid_count += 1
                    isValid = True  # 修正赋值操作

                # 如果同时满足则标记为正确
                if valid and satisfy:
                    correct_count += 1
                    flag = True
                    break  # 成功则跳出尝试循环

            # 记录无法验证的文件
            if not flag:
                error_files.append(file)

            print('-----------------------------------------')

    print_statistics(syntax_count, valid_count, correct_count, file_count, error_files)
    









if __name__ == "__main__":
    main()