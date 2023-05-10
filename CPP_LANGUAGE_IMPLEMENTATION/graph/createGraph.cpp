#include <iostream>
using namespace std;

#define OK 1
#define OVERFLOW -2
#define ERROR -1
#define MAXSIZE 100
#define MaxInt 32767
#define MVNum 100
#define TRUE 1

typedef int Status;
typedef char VerTexType;
typedef int ArcType;
typedef struct
{
    VerTexType vexs[MVNum];
    ArcType arcs[MVNum][MVNum];
    int vexnum, arcnum;
} AMGraph;

int visited[10] = {0};

Status CreateUDN(AMGraph &G);
int LocateVex(AMGraph G, VerTexType u);
Status PrintGraph(AMGraph G);
void DFS(AMGraph G, int v);

int main()
{
    AMGraph G;
    CreateUDN(G);
    PrintGraph(G);
    DFS(G, 3);
}

Status CreateUDN(AMGraph &G)
{
    VerTexType v1, v2;
    int i, j, w;

    cin >> G.vexnum >> G.arcnum;

    for (i = 0; i < G.vexnum; ++i)
        cin >> G.vexs[i];

    for (i = 0; i < G.vexnum; ++i)
        for (j = 0; j < G.vexnum; ++j)
            G.arcs[i][j] = 0;

    for (int k = 0; k < G.arcnum; ++k)
    {
        cout << k + 1 << ": ";
        cin >> v1 >> v2 >> w;
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G.arcs[i][j] = w;
        G.arcs[j][i] = G.arcs[i][j];
    }

    return OK;
}

int LocateVex(AMGraph G, VerTexType u)
{
    int i;
    for (i = 0; i < G.vexnum; ++i)
        if (u == G.vexs[i])
            return i;
    return -1;
}

Status PrintGraph(AMGraph G)
{

    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            cout.width(6);
            cout << G.arcs[i][j];
        }
        cout << endl
             << endl;
    }
    return OK;
}

void DFS(AMGraph G, int v)
{
    cout.width(6);
    cout << v;
    visited[v] = TRUE;
    for (int w = 0; w < G.vexnum; w++)
        if ((G.arcs[v][w] != 0) && (!visited[w]))
            DFS(G, w);
}