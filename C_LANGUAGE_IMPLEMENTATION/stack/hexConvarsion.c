#include <stdio.h>
#include "realizePiece.h"

int main()
{

    int a;

    printf("这是一个数值转换应用\n");

    while (0 == 0)
    {
        int number;
        int hex;
        Stack S;

        initStack(&S);

        printf("请输入要转化的数和进制\n");
        printf("格式为\"number hex\"\n");

        scanf("%d %d", &number, &hex);

        if (number == 0)
        {
            printf("0\n");
            continue;
        }

        while (number)
        {
            push(&S, number % hex);
            number = number / hex;
        }

        while (stackEmpty(S) == 2)
        {
            if (getTop(S) < 10)
                printf("%d", pop(&S));
            else
            {
                ElemType hexOcc1 = pop(&S);
                switch (hexOcc1)
                {
                case 10:
                    printf("A");
                    break;
                case 11:
                    printf("B");
                    break;
                case 12:
                    printf("C");
                    break;
                case 13:
                    printf("D");
                    break;
                case 14:
                    printf("E");
                    break;
                case 15:
                    printf("F");
                    break;
                default:
                    break;
                }
            }
        }
        printf("\n");
    }
    return NORMAL;
}
