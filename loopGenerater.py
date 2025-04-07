from loopProcessor import LoopProcessor
import os
# 获取 input 文件夹路径
input_folder = "sysGus"  # 假设 input 文件夹在当前目录下

# 检查 input 文件夹是否存在
if not os.path.exists(input_folder):
    print(f"Error: The folder '{input_folder}' does not exist.")
    exit(1)

# 获取 input 文件夹中的所有文件
files = os.listdir(input_folder)

# 处理每个文件
for file_name in files:
 
    # 创建 LoopProcessor 对象并执行
    processor = LoopProcessor(file_name)
    processor.init_execute()
    processor.execute()