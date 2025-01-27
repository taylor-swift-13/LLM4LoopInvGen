import os
from outputVerify import OutputVerifier
from invGen import InvGenerator

def print_statistics(correct_count, file_count, error_files):
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
    correct_count = 0

    file_count = 65

    #记录错误的文件名
    error_files = []

    # 遍历文件夹下的所有文件
    for root, dirs, files in os.walk(input_folder):
        for file in files:
            # 检查文件扩展名是否为 .c
            if file.endswith('.c'):
                # 打印文件名
                print("file_name : " + file)

                flag = False
                
                for _ in range(3):
                    generator = InvGenerator()
                    generator.run(file)
                    
                    verifier = OutputVerifier()
                    verifier.run(file)
                    validate_result = verifier.validate_result
                    verify_result = verifier.verify_result

                    valid = bool(validate_result) and all(validate_result)
                    satisfy= bool(verify_result) and all(verify_result)

                    if valid == True and satisfy == True:
                        correct_count = correct_count + 1
                        flag = True
                        break
                
                if flag == False:
                    error_files.append(file)
                    
                print('-----------------------------------------')

    print_statistics(correct_count, file_count, error_files)
    












if __name__ == "__main__":
    main()