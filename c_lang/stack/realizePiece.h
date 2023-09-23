#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100
#define NORMAL 0
#define ERROR -1
#define OVERFLOW -2
#define STACKNULL -3

typedef int Status;
typedef int ElemType;

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
} Stack;

Status initStack(Stack *S)
{
    S->base = (ElemType *)malloc(MaxSize * sizeof(ElemType));
    if (!S->base)
        exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = MaxSize;
    return NORMAL;
}

Status destroyStack(Stack *S)
{
    if (!S->base)
        return ERROR;
    free(S->base);
    S->stacksize = 0;
    S->top = NULL;
    S->base = NULL;
    return NORMAL;
}

Status clearStack(Stack *S)
{
    if (!S->base)
        return ERROR;
    S->top = S->base;
    return NORMAL;
}

Status stackEmpty(Stack S)
{
    if (!S.base)
        return ERROR;
    if (S.top == S.base)
        return 1;
    else
        return 2;
}

Status stackLength(Stack S)
{
    if (!S.base)
        return ERROR;
    return S.top - S.base;
}

Status push(Stack *S, ElemType e)
{
    if (!S->base)
        return ERROR;
    else if (S->base - S->top >= S->stacksize)
        return OVERFLOW;
    *S->top = e;
    S->top++;
    return NORMAL;
}

Status pop(Stack *S)
{
    if (!S->base)
        return ERROR;
    else if (S->base == S->top)
        return STACKNULL;
    ElemType occ;
    occ = *(S->top - 1);
    S->top = S->top - 1;
    return occ;
}

Status getTop(Stack S)
{
    if (!S.base)
        return ERROR;
    else if (S.base == S.top)
        return STACKNULL;
    return *(S.top - 1);
}

Status stackTraverse(Stack S, int (*stackTraverse_out))
{
    if(!S.base)return ERROR;
    else if(S.base==S.top)return STACKNULL;
    for (int i = 0; i < S.top-S.base; i++)
        stackTraverse_out[i] = S.base[i];
    return NORMAL;
}
