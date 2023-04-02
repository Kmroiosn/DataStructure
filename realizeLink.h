/* <license>
 *  This source code is a course assignment for teacher review only,
 *  and is not recommended for other purposes.
 */

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define NORMAL 0
#define ERROR -1
#define OVERFLOW -2
#define STACKNULL -3

typedef int Status;
typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node *next;
} Stack, *LinkStack;

Status initStack(Stack *S)
{
    S = (Stack *)malloc(sizeof(Stack));
    S->next = NULL;
    return NORMAL;
}

Status destroyStack(Stack *S)
{
    if (S)
        S = NULL;
    return NORMAL;
}

Status clearStack(Stack *S)
{
    if (S)
        S->next = NULL;
    return NORMAL;
}

Status stackEmpty(Stack *S)
{
    if (!S)
        return ERROR;
    if (S->next)
        return 1;
    else
        return 2;
}

Status stackLength(Stack *S)
{
    if (!S)
        return ERROR;
    Stack *p;
    int i = 0;
    p = S;
    while (p->next)
    {
        p->next = p->next->next;
        i++;
    }
    return i;
}

Status push(Stack *S, ElemType e)
{
    if (!S)
        return ERROR;
    Stack *p;
    p = (Stack *)malloc(sizeof(Stack));
    p->data = e;
    p->next = S;
    S = p;
    return NORMAL;
}

Status pop(Stack *S)
{
    if (!S)
        return ERROR;
    if (!S->next)
        return STACKNULL;
    Stack *p;
    p = S;
    S = p->next;
    free(p);
    return NORMAL;
}

Status getTop(Stack *S)
{
    if (!S)
        return ERROR;
    if (!S->next)
        return STACKNULL;
    return S->data;
}

Status stackTraverse(Stack *S, int(*stackTraverse_out))
{
    Stack *p;
    p = S;
    int i = 0;
    if (!S)
        return ERROR;
    if (!S->next)
        return STACKNULL;
    while (p->next)
    {
        stackTraverse_out[i] = p->data;
        p = p->next;
        i++;
    }
    return NORMAL;
}
