#include <stdio.h>

int main()
{
    int i = 0;
    int *p = &i;  // 定义指向变量 i 的指针

    i = i + 1;

    printf("%d\n", i);

    while (i)
    {
        printf("address of i: %p\n", (void *)&i);
        i = i << 1;

        printf("%d\n", i);
    }

	// 将i的地址赋予i

    *p = &p;  // 使用指针来更改变量 i 的值

    printf("%x\n", i);  // 输出更改后的变量 i 的值

    return 0;
}
