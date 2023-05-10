cmake_minimum_required(VERSION 3.24)

project(CppImplementationProject)

set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(double_stack.out ./stack/double_stack.cpp)
add_executable(stack.out ./stack/stackMain.cpp)

# compile for ./tree/huffmanTree
add_executable(huffman_tree.out ./tree/huffmanTree/huffmantree.cpp)