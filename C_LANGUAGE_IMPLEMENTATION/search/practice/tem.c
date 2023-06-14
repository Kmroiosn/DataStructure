#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UNITNUM 100

void MakeArray(int *k1) {
    // 使用动态内存分配为每个整数分配内存并赋值
    for (int i = 0; i < UNITNUM; i++) {
        k1[i] = rand() % 90 + 10;
    }
}

void PrintArray(int *k1) {
    // 打印数组中的值
    for (int i = 0; i < UNITNUM; i++) {
        printf("%d ", k1[i]);
    }
    printf("\n");
}

void DeleteArray(int *k1) {
    // 使用完毕后，记得释放内存
    free(k1);
}

void SortArray(int *array) {
    // 为数组排序（这里可以使用任何排序算法）
    #include "Sort.h"
}

int main() {
    int *k1 = malloc(sizeof(int) * UNITNUM); // 动态分配整数数组的内存空间
    srand(time(NULL)); // 使用时间作为种子来初始化随机数生成器
    MakeArray(k1);
    printf("原始数组：\n");
    PrintArray(k1);
    SortArray(k1);
    printf("排序后数组：\n");
    PrintArray(k1);
    DeleteArray(k1);
    return 0;
}
