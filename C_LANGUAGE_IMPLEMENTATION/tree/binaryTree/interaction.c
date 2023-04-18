#include <stdio.h>
#include "realizeLink.h"

#define elif else if

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

    while (1)
    {
        printf("Please choose:\n1.InitBinaryTree\n2.DLRtraverse\n3.LDRtraverse\n4.LRDtraverse\n");
        scanf("%c", &MainIn1);
        if (MainIn1 == '1')
        {
            InitBinaryTree(&T);
            continue;
        }
        elif (MainIn1 == '2')
        {
            Status a[MAXSIZE];
            DLRtraverse(T, a, b);
            PrintA(a);
            continue;
        }
        elif (MainIn1 == '3')
        {
            Status a[MAXSIZE];
            LDRtraverse(T, a, b);
            PrintA(a);
            continue;
        }
        elif (MainIn1 == '4')
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