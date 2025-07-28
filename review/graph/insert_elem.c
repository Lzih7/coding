typedef int VertexType;

typedef enum
{
    DG,
    UDG
} GraphType;

typedef struct ArcNode
{
    int adjvex; // 下标
    InfoPtr *info;
    struct ArcNode *nextarc;

} ArcNode;

typedef struct VNode
{
    VertexType data;
    ArcNode *firstarc;
} VNode;
typedef struct
{
    VNode vertex[MAX_VERTEX_NUM];
    int vexnum, arcnum;
    GraphType type;
} ListGraph;

int locate_vertex(ListGraph *G, VertexType v); // 返回顶点 v 在vertex数组中的下标，如果v不存在，返回-1

/*
bool insert_vertex(ListGraph *G, VertexType v);
bool insert_arc(ListGraph *G, VertexType v, VertexType w);
*/

bool insert_vertex(ListGraph *G, VertexType v)
{
    if (locate_vertex(G, v) != -1)
        return false;
    VNode newnode;
    newnode.data = v;
    newnode.firstarc = NULL;
    G->vertex[G->vexnum] = newnode;
    G->vexnum++;
    return true;
}

// 有向图
bool insert_arc(ListGraph *G, VertexType v, VertexType w)
{
    int v1 = locate_vertex(G, v);
    int w1 = locate_vertex(G, w);
    if (v1 == -1 || w1 == -1)
        return false;

    ArcNode *pre = G->vertex[v1].firstarc;
    ArcNode *p = NULL;
    while (p)
    {
        pre = p;
        if (p->adjvex == w1)
            return false;
        p = p->nextarc;
    }
    ArcNode *arcnode = (ArcNode *)malloc(sizeof(ArcNode));
    arcnode->adjvex = w1;
    arcnode->nextarc = NULL;
    if (pre == NULL)
        arcnode = pre; // 考虑特殊情况
    else
        pre->nextarc = arcnode;

    G->arcnum++;
    return true;
}