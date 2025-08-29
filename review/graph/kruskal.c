#include <stdio.h>
#include <stdbool.h>

/*
 * Kruskal's algorithm for minimum spanning tree
 * adj matrix graph representation
 * arcs是邻接矩阵，VertexSet是顶点集合，lowcost是边的权重
 */

typedef struct Edge
{
    int u, v;
    int lowcost;
} Edge;

static int VertexSet[MAX_VERTEX_NUM]; // 检测是否在同一个分支里

bool Minium(Graph *G, Edge *e)
{
    int i, j;

    e->u = e->v = -1;
    e->lowcost = INFINITY;
    for (i = 0; i < G->vexnum; ++i)
        for (j = 0; j < G->vexnum; ++j)
            if (e->lowcost > G->arcs[i][j].adjvex && VertexSet[i] != VertexSet[j])
            {
                e->lowcost = G->arcs[i][j].adjvex;
                e->u = i;
                e->v = j;
            }

    return e->u != -1;
}

void MiniSpanTree_Kruskal(Graph *gn)
{
    Edge e;
    int i, setid;
    int u, v;

    for (i = 0; i < gn->vexnum; ++i)
        VertexSet[i] = i; // 初始化每个顶点的标签为其自身
    setid = i;

    while (Minium(gn, &e))
    {
        printf("(%s, %s, %d)\n",
               Vertex2Name(gn->vertex[e.u].data),
               Vertex2Name(gn->vertex[e.v].data),
               e.lowcost); /*输出生成树的当前最小边（u,v）*/

        Setu = VertexSet[e.u];
        Setv = VertexSet[e.v];
        for (i = 0; i < gn->vexnum; ++i)
            if (VertexSet[i] == Setu || VertexSet[i] == Setv)
                VertexSet[i] = setid; // 将u和v所在的集合合并
        ++setid;
    }
}

int main(int argc, char *argv[])
{
    choose_graph_model("kruskal", argc >= 2, argv, NULL);
    graph_figure();

    Graph G;
    CreateGraph(&G);

    FillVertexMap(G.vexnum);

    MiniSpanTree_Kruskal(&G);

    DestroyGraph(&G);

    close_model();

    return 0;
}