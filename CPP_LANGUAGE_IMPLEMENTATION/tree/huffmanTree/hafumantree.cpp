// <- GB 2312 ->

#include <iostream>
using namespace std;

#define OK 1
#define OVERFLOW -2
#define ERROR -1
#define MAXSIZE 100 //?????

typedef int Status;

typedef struct
{
    int weight;
    int parent, lch, rch;
} *HuffmanTree, HTNode;

void CreatHuffmanTree(HuffmanTree HT, int n);
void Select(HuffmanTree HT, int n, int &min1, int &min2);

int main()
{
    HuffmanTree HT;
    CreatHuffmanTree(HT, 4);
    for (int i = 1; i <= 4; i++)
    {
        cout << HT[i].weight << "   " << HT[i].parent << "   " << HT[i].lch << "   "
             << "   " << HT[i].rch;
        cout << endl;
    }
}

void CreatHuffmanTree(HuffmanTree HT, int n)
{
    int m, s1, s2;
    if (n <= 1)
        return;
    m = 2 * n - 1;
    HT = new HTNode[m + 1]; // 0�ŵ�Ԫδ�ã�HT[m]��ʾ�����
    for (int i = 1; i <= m; ++i)
    {
        HT[i].lch = 0;
        HT[i].rch = 0;
        HT[i].parent = 0;
    }

    cout << "Enter " << n << " �����Ȩ��: ";
    for (int i = 1; i <= n; ++i)
        cin >> HT[i].weight;

    for (int i = n + 1; i <= m; ++i)
    { // ����  Huffman��
        Select(HT, i - 1, s1, s2);
        // ��HT[k](1��k��i-1)��ѡ��������˫����Ϊ0,
        //  ��Ȩֵ��С�Ľ��,
        //  ������������HT�е����s1��s2
        cout << s1 << "   " << s2 << endl;

        HT[s1].parent = i;
        HT[s2].parent = i;
        // ��ʾ��F��ɾ��s1,s2
        HT[i].lch = s1;
        HT[i].rch = s2;
        // s1,s2�ֱ���Ϊi�����Һ���
        HT[i].weight = HT[s1].weight + HT[s2].weight;
        // i ��ȨֵΪ���Һ���Ȩֵ֮��
    }
}

void Select(HuffmanTree HT, int n, int &min1, int &min2)
{

    min1 = min2 = 1;

    for (int i = 1; i < n; i++)
    {
        if (HT[i].weight < HT[min1].weight)
        {
            min2 = min1;
            min1 = i;
        }
        else if (HT[i].weight < HT[min2].weight)
            min2 = i;
    }
}
