#include <stdio.h>
#include "realize.h"

int main()
{
    int *n = malloc(3* sizeof(int));

    for (int i = 0; i < 3; i++)
        scanf("%d", &n[i]);
    for (int i = 0; i < 3; i++)
        printf("%d", n[i]);
    printf("\n");
    return 0;
}