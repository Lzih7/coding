#include <bits/stdc++.h>
using namespace std;
/*
 * 遍历所有节点
 */
class Vertex
{
public:
    int id;
    vector<Vertex *> neighbors;
};

void traverse(Vertex *s, vector<bool> visited)
{
    if (s == nullptr)
        return;
    if (visited[s->id])
        return;
    for (auto neighbor : s->neighbors)
    {
        visited[s->id] = true;
        cout << "Visiting vertex: " << s->id << endl;
        if (!visited[neighbor->id])
        {
            traverse(neighbor, visited);
        }
    }
}

int main()
{
    // 创建图的顶点
    Vertex v0, v1, v2, v3;
    v0.id = 0;
    v1.id = 1;
    v2.id = 2;
    v3.id = 3;

    // 设置邻接关系
    v0.neighbors = {&v1, &v2};
    v1.neighbors = {&v0, &v3};
    v2.neighbors = {&v0};
    v3.neighbors = {&v1};

    // 初始化访问标记
    vector<bool> visited(4, false);

    // 从顶点0开始遍历
    traverse(&v0, visited);

    return 0;
}