#include <stdlib.h>
#include <time.h>

#define OK 0
#define ERROR -1
#define OVERFLOW -2
#define NOTFOUND -3
#define MAXSIZE 100
#define NAMELENGTH 3

typedef int Status;
typedef int KeyType;

typedef struct
{
    int id;     // 学生ID
    char *name; // 学生姓名
} InfoType;

typedef struct
{
    KeyType key;        // 关键字域
    InfoType otherinfo; // 其他域
} ElemType;

typedef struct
{
    ElemType *R; // 表基址
    int length;  // 表长
} SSTable;

/**
 * 生成一个随机的ElemType单元
 * 包含随机的关键字、学生ID和学生姓名
 */
ElemType MakeUnit()
{
    ElemType oput;

    oput.key = rand() % 90 + 10; // 生成10到99之间的随机数作为关键字

    oput.otherinfo.name = (char *)malloc((NAMELENGTH + 1) * sizeof(char)); // 为姓名分配内存空间

    for (int i = 0; i < NAMELENGTH; i++)
    {
        // 生成随机的字母 ASCII 码，范围为 'A' (65) 到 'Z' (90)
        int ascii_code = rand() % 26 + 65;
        // 将 ASCII 码转换为对应的字母
        oput.otherinfo.name[i] = (char)ascii_code;
    }
    oput.otherinfo.name[NAMELENGTH] = '\0'; // 字符串结尾添加'\0'

    return oput;
}

/**
 * 初始化顺序表
 * 分配内存空间并生成随机的ElemType元素
 * 参数：
 *     ST: 顺序表指针
 *     n: 顺序表长度
 * 返回值：
 *     初始化成功返回OK，否则返回OVERFLOW
 */
int InitList_Sq(SSTable *ST, int n)
{
    ST->R = (ElemType *)malloc((n + 1) * sizeof(ElemType)); // 为顺序表分配空间
    if (ST->R == NULL)
        return OVERFLOW; // 存储分配失败
    for (int i = 0; i < n; i++)
    {
        ElemType unit = MakeUnit();    // 生成随机的ElemType单元
        ST->R[i].otherinfo.id = i + 1; // 生成学生ID
        ST->R[i].key = unit.key;
        ST->R[i].otherinfo.name = unit.otherinfo.name;
    }
    ST->length = n; // 表长度为n
    return OK;
}

/**
 * 顺序查找
 * 在顺序表中查找指定关键字的元素
 * 参数：
 *     ST: 顺序表
 *     key: 要查找的关键字
 * 返回值：
 *     若成功返回其位置信息，否则返回OK
 */
int Search_Seq(SSTable ST, KeyType key)
{
    // 若成功返回其位置信息，否则返回NOTFOUND
    for (int i = 0; i < ST.length; i++)
    { // 从前往后找
        if (ST.R[i].key == key)
            return ST.R[i].otherinfo.id;
    }
    return NOTFOUND;
}

int Search_Bin(SSTable ST, KeyType key)
{
    int i = 0;
}

int InsertSort(SSTable *ST, int n)
{
    for (int i = 0; i < ST->length; i++)
    {
        if (ST->R[i].key > ST->R[i + 1].key)
        {
            ElemType tem;
            tem = ST->R[i];
            ST->R[i] = ST->R[i + 1];
            // for (int j = i + 1; ST->R[i].key < ST->R[j].key; j++)
            //     ST->R[j + 1] = ST->R[j];
            ST->R[i + 1] = tem;
        }
    }
    return OK;
}

/**
 * 删除顺序表
 * 释放顺序表的内存空间
 * 参数：
 *     ST: 顺序表指针
 * 返回值：
 *     删除成功返回OK
 */
int delete_sq(SSTable *ST)
{
    free(ST->R);
    return OK;
}
