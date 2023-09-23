#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define OK 1
#define OVERFLOW -2
#define ERROR -1
#define MAXSIZE 100

typedef int Status;
typedef int KeyType;
typedef int InfoType;

typedef struct
{
	KeyType key;		// 关键字域
	InfoType otherinfo; // 其他域
} ElemType;

typedef struct
{
	ElemType *R; // 表基址
	string	name[11];
	int length;	 // 表长
} SSTable, * pST;

#define N 10
Status InitList_Sq(SSTable &ST, int n);
Status InitList_Sort_Sq(SSTable &ST, int n);
void SelectSort(SSTable &ST);
int Search_Seq(SSTable ST, KeyType key);
int Search_Bin(SSTable ST, KeyType key);
void PrintSeq(SSTable ST);

int main()
{
	SSTable ST;
	int choice;
	int flag = true;
	KeyType key;
	while (flag)
	{
		cout << endl
			 << endl;
		cout << "       顺序表查找          \n";
		cout << "---------------------------\n";
		cout << " 1. 建立顺序表            \n";
		cout << " 2. 建立有序顺序表        \n";
		cout << " 3. 输出顺序表             \n";
		cout << " 4. 顺序查找              \n";
		cout << " 5. 折半查找              \n";
		cout << " 0. 退出                  \n";
		cout << "---------------------------\n";
		cout << "请选择(0--3)：";
		cin >> choice;
		switch (choice)
		{
		case 1:
			InitList_Sq(ST, N);
			break;
		case 2:
			InitList_Sort_Sq(ST, N);
			break;
		case 3:
			PrintSeq(ST);
			break;
		case 4:
			cout << "输入查找关键字：";
			cin >> key;
			cout << "该元素在表中的位置：" << Search_Seq(ST, key);
			break;
		case 5:
			cout << "输入查找关键字：";
			cin >> key;
			cout << "该元素在表中的位置：" << Search_Bin(ST, key);
			break;
		case 0:
			flag = false;
			break;
		default:
			cout << "选择错误，重选！\n";
		}
	}
	return 0;
}

Status InitList_Sq(SSTable &ST, int n)
{								  // 构造一个空的顺序表L
	ST.R = new ElemType[MAXSIZE]; // 为顺序表分配空间
	if (!ST.R)
		exit(OVERFLOW); // 存储分配失败

	for (int i = 1; i <= n; i++) // 随机产生n个两位整数
		ST.R[i].key = rand() % 90 + 10;

	ST.length = n; // 表长度为n
	PrintSeq(ST);
	return OK;
}

Status InitList_Sort_Sq(SSTable &ST, int n)
{								  // 构造一个空的顺序表L
	ST.R = new ElemType[MAXSIZE]; // 为顺序表分配空间
	if (!ST.R)
		exit(OVERFLOW); // 存储分配失败

	for (int i = 1; i <= n; i++) // 随机产生n个两位整数
		ST.R[i].key = rand() % 90 + 10;

	ST.length = n; // 表长度为n

	SelectSort(ST); // 顺序表排序

	PrintSeq(ST);

	return OK;
}

void SelectSort(SSTable &ST) // 选择排序
{
	int i, j, k, t;
	for (i = 1; i < ST.length; ++i)
	{ // 在ST.R[i..ST.length] 中选择key最小的记录
		k = i;
		for (j = i + 1; j <= ST.length; j++)
			if (ST.R[j].key < ST.R[k].key)
				k = j;
		if (k != i)
		{
			t = ST.R[i].key;
			ST.R[i].key = ST.R[k].key;
			ST.R[k].key = t;
		}
	}
}

int Search_Seq(SSTable ST, KeyType key)
{
	// 若成功返回其位置信息，否则返回0
	int i;
	ST.R[0].key = key;
	for (i = ST.length; ST.R[i].key != key; --i)
		; // 从后往前找
	return i;
}

int Search_Bin(SSTable ST, KeyType key)
{
	// 若找到，则函数值为该元素在表中的位置，否则为0
	int low, high, mid;
	low = 1;
	high = ST.length;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (key == ST.R[mid].key)
			return mid;
		else if (key < ST.R[mid].key)
			high = mid - 1; // 前一子表查找
		else
			low = mid + 1; // 后一子表查找
	}
	return 0; // 表中不存在待查元素
}

void PrintSeq(SSTable ST)
{

	cout << "顺序表：";
	for (int i = 1; i <= ST.length; i++) // 随机产生n个两位整数
		cout << ST.R[i].key << "\t";

	cout << endl;
}
