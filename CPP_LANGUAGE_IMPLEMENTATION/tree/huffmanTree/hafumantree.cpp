#include <iostream>

using namespace std;

#define OK 0
#define ERROR -1
#define OVERFLOW -2
#define MAXSIZE 100

typedef int Status;

typedef struct
{
    int weight;
    int parent, left_child, right_child;
} *huffman_tree, huffman_tree_node;

void creatHuffmanTree(huffman_tree HT, int n);
void Select(huffman_tree HT, int n, int &min1, int &min2);

int main()
{
    int n = 10;
    huffman_tree HT;
    creatHuffmanTree(HT, n);
    for (int i = 1; i <= n; i++)
        cout << HT[i].weight << "\t"
        << HT[i].parent << "\t"
        << HT[i].left_child << "\t"
        << HT[i].right_child << endl;
    return 0;
}

void creatHuffmanTree(huffman_tree HT, int n)
{
    int m, s1, s2;
    if (n <= 1)
        return;
    m = 2 * n - 1;
    HT = new huffman_tree_node[m + 1];
    for (int i = 1; i <= m; ++i)
    {
        HT[i].left_child = 0;
        HT[i].right_child = 0;
        HT[i].parent = 0;
    }
    cout << "Enter " << n << "number" << endl;
    for (int i = 1; i <= n; ++i)
        cin >> HT[i].weight;
    for (int i = n + 1; i <= m; ++i)
    {
        Select(HT, i - 1, s1, s2);
        cout << s1 << "\t" << s2 << endl;

        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].left_child = s1;
        HT[i].right_child = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
}

void Select(huffman_tree HT, int n, int &min1, int &min2)
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