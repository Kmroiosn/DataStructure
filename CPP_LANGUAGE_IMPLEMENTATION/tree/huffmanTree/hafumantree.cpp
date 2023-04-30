#include <iostream>

using namespace std;

#define OK 1
#define OVERFLOW -2
#define ERROR -1
#define MAXSIZE 100

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
    int n = 10;
    HuffmanTree HT;
    CreatHuffmanTree(HT, n);
    for (int i = 1; i <= n; i++)
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
    HT = new HTNode[m + 1];
    for (int i = 1; i <= m; ++i)
    {
        HT[i].lch = 0;
        HT[i].rch = 0;
        HT[i].parent = 0;
    }

    cout << "Enter " << n << "number";
    for (int i = 1; i <= n; ++i)
        cin >> HT[i].weight;

    for (int i = n + 1; i <= m; ++i)
    {
        Select(HT, i - 1, s1, s2);
        cout << s1 << "   " << s2 << endl;

        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lch = s1;
        HT[i].rch = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
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