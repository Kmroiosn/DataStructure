#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define NORMAL 0
#define ERROR -1

typedef int Status;
typedef int TreeElemType;
typedef struct BinaryTreeNode
{
    TreeElemType data;
    struct BinaryTreeNode *leftchild, *rightchild;
} BiTNode, *BinaryTree;

Status InitBinaryTree(BinaryTree *Tree)
{
    *Tree = NULL;
    return NORMAL;
}

Status DLRtraverse(BinaryTree Tree, Status a[], int *b)
{
    if (Tree)
    {
        a[(*b)++] = Tree->data;
        DLRtraverse(Tree->leftchild, a, b);
        DLRtraverse(Tree->rightchild, a, b);
    }
    else
        return ERROR;
    return NORMAL;
}

Status LDRtraverse(BinaryTree Tree, Status a[], int *b)
{
    if (Tree)
    {
        LDRtraverse(Tree->leftchild, a, b);
        a[(*b)++] = Tree->data;
        LDRtraverse(Tree->rightchild, a, b);
    }
    else
        return ERROR;
    return NORMAL;
}

Status LRDtraverse(BinaryTree Tree, Status a[], int *b)
{
    if (Tree)
    {
        LRDtraverse(Tree->leftchild, a, b);
        LRDtraverse(Tree->rightchild, a, b);
        a[(*b)++] = Tree->data;
    }
    else
        return ERROR;
    return NORMAL;
}