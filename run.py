
from invGen import InvGenerator
from loopProcessor import LoopProcessor
import argparse

if __name__ == "__main__":

    # 创建解析器
    parser = argparse.ArgumentParser(description="Read file_name from command-line arguments.")
    parser.add_argument('file_name', type=str, help="The name of the file without extension")

    # 解析参数
    args = parser.parse_args()
    # 创建 LoopProcessor 对象并执行

    processor = LoopProcessor(args.file_name)
    processor.init_execute()
    processor.execute()

    generator = InvGenerator()
    generator.run(args.file_name)




