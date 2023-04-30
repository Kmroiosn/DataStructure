# 这是`./test.sh`的文档

## `./test.sh`的作用

用于自动调试`./hafumantree.cpp`文件

## `./test.sh`的分析(From ChatGPT)<!-- 注意及时更新 -->

```
这段代码是一个 shell script 脚本，它的作用是编译一个名为 hafumantree 的源代码文件，并以随机数为输入参数来运行它。脚本的流程如下：

使用 make 命令编译名为 hafumantree 的源代码文件。
使用循环语句生成 10 个随机数，并将它们保存到 input 数组中。
使用 echo 命令输出 input 数组中的元素，并调用 lineSeparator 函数输出一条分割线。
使用管道符号 | 将 input 数组中的元素作为输入传递给 ./hafumantree.out 命令，运行可执行文件。
调用 lineSeparator 函数输出一条分割线。
其中，lineSeparator 函数是一个自定义的输出分割线的函数，它使用循环语句输出一定数量的星号（这里是 100 个），然后输出一个换行符，最后返回值为 0。
```

## 一些问题

在调用了`lineSeparator()`函数生成分割行后，貌似该函数后跟随的shell script结构和命令会失效
解决方法：删除`lineSeparator()`，但会失去分割行，不过能完成其他功能
