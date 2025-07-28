#include <stdio.h>
#include <stdbool.h>

typedef struct
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
        VertexSet[i] = i;
    setid = i;

    while (Minium(gn, &e))
    {
        printf("(%s, %s, %d)\n",
               Vertex2Name(gn->vertex[e.u].data),
               Vertex2Name(gn->vertex[e.v].data),
               e.lowcost); /*输出生成树的当前最小边（u,v）*/

        u = VertexSet[e.u];
        v = VertexSet[e.v];
        for (i = 0; i < gn->vexnum; ++i)
            if (VertexSet[i] == u || VertexSet[i] == v)
                VertexSet[i] = setid;
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