#!/usr/bin/env python3

import os
import random

def line_separator():
    for i in range(100):
        print("*", end="")
    print("")

# use "make" to build executable from source code
os.system("make")

input = [random.randint(0, 100) for i in range(10)]

# print input parameters
print("input:")

line_separator()

for i in range(10):
    print(input[i])

line_separator()

os.system(f"echo {' '.join(map(str, input))} | ./huffmantree.out")

# use "make clean" to remove the executable
os.system("make clean")