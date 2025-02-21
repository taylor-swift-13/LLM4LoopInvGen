import argparse
import subprocess
import os

def delete_file_if_exists(file_path):
    """如果文件存在，则删除文件"""
    # 构建完整的文件路径
    file_path = os.path.join('../sac_c_parser/test', file_path)

    if os.path.exists(file_path):  # 检查文件是否存在
        print(f"File found: {file_path}. Deleting the file.")
        os.remove(file_path)  # 删除文件
    else:
        print(f"File not found: {file_path}. No file to delete.")

def main():
    # 创建解析器
    parser = argparse.ArgumentParser(description="Read file_name from command-line arguments.")

    # 添加一个必需的参数 file_name
    parser.add_argument('file_name', type=str, help="The name of the file without extension")

    parser.add_argument('-r', action='store_true', help="print return of everyfunction")

    # 解析参数
    args = parser.parse_args()

    # 解析参数，去掉文件扩展名
    file_name = args.file_name.split('.')[0]

    # 定义文件路径
    goal_file = f"../ip_postcond/goal/{file_name}_goal.v"
    proof_auto_file = f"../ip_postcond/goal/{file_name}_proof_auto.v"
    proof_manual_file = f"../ip_postcond//goal/{file_name}_proof_manual.v"
    
    
    # 检查文件是否存在，存在则删除
    for file_path in [goal_file, proof_auto_file, proof_manual_file]:
        delete_file_if_exists(file_path)
    
    # build/symexec --goal-file=../../SeparationLogic/examples/sll_goal.v 
    # --proof-auto-file=../../SeparationLogic/examples/sll_proof_auto.v 
    # --proof-manual-file=../../SeparationLogic/examples/sll_proof_manual.v 
    # --input-file=../examples/sll.c;

    # 定义命令和参数
    command = [
        "build/symexec",
        f"--goal-file={goal_file}",
        f"--proof-auto-file={proof_auto_file}",
        f"--proof-manual-file={proof_manual_file}",
        f"--input-file=../../LoopInvGen_V/output/{file_name}.c"
    ]
    

    

    # 运行命令，捕获输出
    try:
        result = subprocess.run(command, cwd='../sac_c_parser/test', stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        

        # 打印标准输出和错误
        print("Standard Output:")
        print(result.stdout)
        if result.stderr:
            print("Error Output:")
            print(result.stderr)
    
    except Exception as e:
        print(f"An error occurred: {e}")


       

        
    
if __name__ == "__main__":
    main()
