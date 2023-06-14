import os
import sys

def main():
    script = """
    gcc -g tem.c -o tem
    gdb tem
    rm tem
    """
    os.system(script)

def NotDebug():
    script = """
    gcc tem.c -o tem
    ./tem
    rm tem
    """
    os.system(script)

# 检查参数个数
if len(sys.argv) <= 1:
    # 没有传递参数时
    main()

else:
    # 有参数时获取命令行参数
    arguments = sys.argv

    if(arguments[1] == '-n'):
        NotDebug()