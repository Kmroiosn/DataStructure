#include <stdlib.h>

#define OK 0
#define ERROR -1
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;

typedef struct
{
    int weight;
    int parent, left_child, right_child;
} *huffman_tree, huffman_tree_node;

Status createHuffmanTree(huffman_tree* huffman_tree_parameter, int n, int loop_step);

Status createHuffmanTree(huffman_tree* huffman_tree_parameter, int n, int loop_step)
{
    if (n <= 1)
        return OK;
    int m = 2 * n - 1;
    huffman_tree_parameter = (huffman_tree*)malloc((m + 1) * sizeof(huffman_tree_node));
    for (int i = 1; i <= m; ++i)
    {
        huffman_tree_parameter[i]->parent = 0;
        huffman_tree_parameter[i]->left_child = 0;
        huffman_tree_parameter[i]->right_child = 0;
    }
    for (int i = 1; i <= n; ++i)
        huffman_tree_parameter[i]->weight;

    free(huffman_tree_parameter);
}