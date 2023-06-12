#include <stdio.h>
#include <stdlib.h>
#include "./realize.h"

int main()
{
	SSTable ST;

	while (0 == 0)
	{

		char choice = '0';

		printf("%s", "       顺序表操作          \n");
		printf("%s", "---------------------------\n");
		printf("%s", " 1. 建立顺序表            \n");
		printf("%s", " 2. 打印顺序表            \n");
		printf("%s", " 3. 顺序查找              \n");
		printf("%s", " 4. 折半查找              \n");
		printf("%s", " 5. 插入排序              \n");
		printf("%s", " 6. 选择排序              \n");
		printf("%s", " 7. 冒泡排序              \n");
		printf("%s", " 8. 快速排序              \n");
		printf("%s", "---------------------------\n");
		printf("%s", "请选择操作:");

		scanf(" %c", &choice);

		switch (choice)
		{
		case '1':
			printf("%d\n", InitList_Sq(&ST, 10));
			break;
		case '2':
			for (int i = 0; i < ST.length; i++)
			{
				printf("Key: %d\tName: ", ST.R[i].key);
				for (int i1 = 0; i1 <= NAMELENGTH; i1++)
					printf("%c", ST.R[i].otherinfo.name[i1]);
				printf("\tID: %d\n", ST.R[i].otherinfo.id);
			}
			break;
		case '3':
			printf("输入要查找的值：");
			int main_input3;
			scanf(" %d", &main_input3);
			int main_temvar3 = Search_Seq(ST, main_input3);
			if (main_temvar3 == -3)
				printf("没找到对应值\n");
			else
				printf("%d\n", main_temvar3);
			break;
		case '4':
			printf("输入要查找的值：");
			int main_input4;
			scanf(" %d", &main_input4);
			int main_temvar4 = Search_Bin(ST, main_input4);
			if (main_temvar4 == -3)
				printf("没找到对应值\n");
			else
				printf("%d\n", main_temvar4);
			break;
		case '5':
			printf("%d\n", InsertSort(&ST, ST.length));
			break;
		case '6':
			printf("%d\n", SelectionSort(&ST, ST.length));
			break;
		case '7':
			printf("%d\n", BubbleSort(&ST, ST.length));
			break;
		case '8':
			printf("%d\n", QuickSort(&ST,0, ST.length));
			break;
		case 'q':
			delete_sq(&ST);
			return OK;
		}
	}
}