#include <iostream>
#include <stdlib.h>
#define Inf 1000000
#define Init -1
#define MaxVertex 100
typedef int Vertex;
int G[MaxVertex][MaxVertex];
int dest[MaxVertex];      // 距离
int path[MaxVertex];      // 路径
int collected[MaxVertex]; // 被收录集合
int Nv;                   // 顶点
int Ne;                   // 边
using namespace std;

// 初始化图信息
void build()
{
    Vertex v1, v2;
    int w;
    cin >> Nv;
    // 初始化图
    for (int i = 1; i <= Nv; i++)
        for (int j = 1; j <= Nv; j++)
            G[i][j] = 0;
    // 初始化路径
    for (int i = 1; i <= Nv; i++)
        path[i] = Init;
    // 初始化距离
    for (int i = 0; i <= Nv; i++)
        dest[i] = Inf;
    // 初始化收录情况
    for (int i = 1; i <= Nv; i++)
        collected[i] = false;
    cin >> Ne;
    // 初始化点
    for (int i = 0; i < Ne; i++)
    {
        cin >> v1 >> v2 >> w;
        G[v1][v2] = w; // 有向图
    }
}

// 初始化距离和路径信息
void create(Vertex s)
{
    dest[s] = 0;
    collected[s] = true;
    for (int i = 1; i <= Nv; i++)
        if (G[s][i])
        {
            dest[i] = G[s][i];
            path[i] = s;
        }
}

// 查找未收录顶点中dest最小者
Vertex FindMin(Vertex s)
{
    int min = 0; // 之前特地把 dest[0] 初始化为正无穷
    for (Vertex i = 1; i <= Nv; i++)
        if (i != s && dest[i] < dest[min] && !collected[i])
            min = i;
    return min;
}

void Dijkstra(Vertex s)
{
    create(s);
    while (true)
    {
        Vertex V = FindMin(s); // 找到
        if (!V)
            break;
        collected[V] = true; // 收录
        for (Vertex W = 1; W <= Nv; W++)
            if (!collected[W] && G[V][W])
            { // 如果未被收录
                if (dest[V] + G[V][W] < dest[W])
                {
                    dest[W] = G[V][W] + dest[V];
                    path[W] = V;
                }
            }
    }
}

void output()
{
    for (int i = 1; i <= Nv; i++)
        cout << dest[i] << " ";
    cout << endl;
    for (int i = 1; i <= Nv; i++)
        cout << path[i] << " ";
    cout << endl;
}

int main()
{
    build();
    Dijkstra(1);
    output();
    return 0;
}