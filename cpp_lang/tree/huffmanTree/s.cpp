// 导入实现基本操作需要的库
#include <iostream>
// 定义命名空间（我也不太懂）
using namespace std;
// 定义特殊字符及其值
#define OK 0
#define ERROR -1
#define OVERFLOW -2
#define MAXSIZE 100
// 定义元素数据类型
typedef int Status;
// 定义数据结构
typedef struct
{
    int weight;
    int parent, left_child, right_child;
} *huffman_tree, huffman_tree_node;
// 声明两个函数，返回值为空
void creatHuffmanTree(huffman_tree huffman_tree_parameter, int n);
void Select(huffman_tree huffman_tree_parameter, int n, int &min1, int &min2);
// 主函数
int main()
{
    int n = 10;
    huffman_tree huffman_tree_parameter;
    creatHuffmanTree(huffman_tree_parameter, n);
    // 输出HT的各个结点值
    for (int i = 1; i <= n; i++)
        cout << huffman_tree_parameter[i].weight << "\t"
        << huffman_tree_parameter[i].parent << "\t"
        << huffman_tree_parameter[i].left_child << "\t"
        << huffman_tree_parameter[i].right_child << endl;
    // 主函数返回
    return 0;
}

void creatHuffmanTree(huffman_tree huffman_tree_parameter, int n)
{// 定义
    int m, s1, s2;
    // 如果n<=1，返回（即结束这个函数）
    if (n <= 1)
        return;
    // 新建储存所有树的空间HT
    m = 2 * n - 1;
    huffman_tree_parameter = new huffman_tree_node[m + 1];
    // 使HT储存的所有树的左右父结点为0，即初始化
    for (int i = 1; i <= m; ++i)
    {
        huffman_tree_parameter[i].left_child = 0;
        huffman_tree_parameter[i].right_child = 0;
        huffman_tree_parameter[i].parent = 0;
    }
    // 提示输入
    cout << "Enter " << n << "number" << endl;
    // 将输入存入每一个树的权重中
    for (int i = 1; i <= n; ++i)
        cin >> huffman_tree_parameter[i].weight;
    // 合并树
    for (int i = n + 1; i <= m; ++i)
    {
        Select(huffman_tree_parameter, i - 1, s1, s2);

        cout << s1 << "\t" << s2 << endl;
        // 这一段是要合并树的，但没有完成
        huffman_tree_parameter[s1].parent = i;
        huffman_tree_parameter[s2].parent = i;
        huffman_tree_parameter[i].left_child = s1;
        huffman_tree_parameter[i].right_child = s2;
        huffman_tree_parameter[i].weight = huffman_tree_parameter[s1].weight + huffman_tree_parameter[s2].weight;
    }
}

void Select(huffman_tree huffman_tree_parameter, int n, int &min1, int &min2)
{
    min1 = min2 = 1;
    for (int i = 1; i < n; i++)
    {
        // 如果标号为i的树的权小于标号为min1的树的权
        // 将min1存入min2，将i存入min1
        if (huffman_tree_parameter[i].weight < huffman_tree_parameter[min1].weight)
        {
            min2 = min1;
            min1 = i;
        }
        // 如果如果标号为i的树的权小于标号为min2的树的权
        // 将i存入min2
        else if (huffman_tree_parameter[i].weight < huffman_tree_parameter[min2].weight)
            min2 = i;
    }
}