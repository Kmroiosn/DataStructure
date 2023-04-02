/* <licence>
 *  This source code is a course assignment for teacher review only,
 *  and is not recommended for other purposes.
 */

#include <stdio.h>
#include "realizeLink.h"

int main()
{

    char mainIn1;
    Stack S;

    initStack(&S);

    printf("这是一个对栈的操作应用\n");

    while (1)
    {
        printf("请选择你的操作：\n");
        printf("1->清空栈S\n");
        printf("2->判断栈S是否为空\n");
        printf("3->查看栈S的元素个数\n");
        printf("4->入栈S\n");
        printf("5->出栈S\n");
        printf("6->查看栈S的栈顶元素\n");
        printf("7->从栈底到栈顶遍历栈S的每个数据元素\n");

        scanf("%c", &mainIn1);

        if (mainIn1 == 'q')
            break;
        switch (mainIn1)
        {
        case '1':
            clearStack(&S);
            break;
        case '2':
            if (stackEmpty(S) == 1)
                printf("栈S为空\n");
            else if (stackEmpty(S) == 2)
                printf("栈S不为空\n");
            break;
        case '3':
            printf("栈S的元素个数为:%d\n", stackLength(S));
            break;
        case '4':
            int interOcc4;
            printf("输入要入栈的数:");
            scanf("%d", &interOcc4);
            push(&S, interOcc4);
            break;
        case '5':
            printf("%d\n", pop(&S));
            break;
        case '6':
            printf("%d\n", getTop(S));
            break;
        case '7':
            int * interOcc7 = NULL;
            interOcc7 = malloc(sizeof(int)*10);
            stackTraverse(S, interOcc7);
            for (int i = 0; i < S.top-S.base; i++)
                printf("%d\n",interOcc7[i]);
            break;
        default:
            break;
        }
    }

    destroyStack(&S);
    return NORMAL;
}