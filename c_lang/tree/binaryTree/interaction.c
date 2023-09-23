#include <stdio.h>
#include "realizeLink.h"

int PrintA(Status a[])
{
    int b = 0;
    while (1)
    {
        if (a[b])
            printf("%d: %d\n", b, a[b]);
        else
            break;
        b++;
    }
    return NORMAL;
}

int main(void)
{

    BinaryTree T;
    int* b = 0;
    char MainIn1;

    // this is a test tree
    T->data = *(Status*)malloc(sizeof(Status));
    T->data = 1;
    T->leftchild->data = *(Status*)malloc(sizeof(Status));
    T->leftchild->data = 0;
    // T->rightchild->data = 1;
    // T->leftchild->leftchild->data = 1;
    // T->leftchild->rightchild->data = 0;

    while (1)
    {
        printf("Please choose:\n1.InitBinaryTree\n2.DLRtraverse\n3.LDRtraverse\n4.LRDtraverse\n");
        scanf("%c", &MainIn1);
        if (MainIn1 == '1')
        {
            InitBinaryTree(&T);
            continue;
        }
        else if (MainIn1 == '2')
        {
            Status a[MAXSIZE];
            DLRtraverse(T, a, b);
            PrintA(a);
            continue;
        }
        else if (MainIn1 == '3')
        {
            Status a[MAXSIZE];
            LDRtraverse(T, a, b);
            PrintA(a);
            continue;
        }
        else if (MainIn1 == '4')
        {
            Status a[MAXSIZE];
            LRDtraverse(T, a, b);
            PrintA(a);
            continue;
        }
        // else break;
    }
    return NORMAL;
}