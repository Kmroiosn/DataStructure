cmake_minimum_required(VERSION 3.24)

if (WIN32)
    message(STATUS "Under Windows platform")
    message(STATUS "Set compiler to clang / clang++ ...")
    set(CMAKE_C_COMPILER    "D:/Compilers/mingw64/bin/clang.exe")
    set(CMAKE_CXX_COMPILER  "D:/Compilers/mingw64/bin/clang++.exe")

elseif(UNIX)
    message(STATUS "Under Unix-like platform")

elseif(APPLE)
    message(STATUS "Under Apple platform")

endif ()

project(CppImplementationProject)

set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# stack
add_executable(double_stack.out ./stack/double_stack.cpp)
add_executable(stack.out ./stack/stackMain.cpp)

# tree
add_executable(binary_tree.out ./tree/binaryTree/binary_tree.cpp)
add_executable(huffman_tree.out ./tree/huffmanTree/huffmantree.cpp)