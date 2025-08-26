#include <stdio.h>
#include <stdlib.h>

// 邻接表中的边节点
struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
};

// 邻接表
struct AdjList
{
    struct AdjListNode *head;
};

// 图结构
struct Graph
{
    int numVertices;
    struct AdjList *array;
};

// 创建新的邻接表节点
struct AdjListNode *createNode(int dest)
{
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// 创建图
struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;
    graph->array = (struct AdjList *)malloc(numVertices * sizeof(struct AdjList));

    for (int i = 0; i < numVertices; i++)
    {
        graph->array[i].head = NULL;
    }

    return graph;
}

// 添加边（无向图）
void addEdge(struct Graph *graph, int src, int dest)
{
    // 从src到dest添加边
    struct AdjListNode *newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // 从dest到src添加边
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// 添加有向边
void addDirectedEdge(struct Graph *graph, int src, int dest)
{
    struct AdjListNode *newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// 打印图
void printGraph(struct Graph *graph)
{
    for (int v = 0; v < graph->numVertices; v++)
    {
        struct AdjListNode *temp = graph->array[v].head;
        printf("\n顶点 %d 的邻接顶点: ", v);
        while (temp)
        {
            printf("%d -> ", temp->dest);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// 释放图内存
void freeGraph(struct Graph *graph)
{
    if (graph)
    {
        if (graph->array)
        {
            for (int i = 0; i < graph->numVertices; i++)
            {
                struct AdjListNode *temp = graph->array[i].head;
                while (temp)
                {
                    struct AdjListNode *toDelete = temp;
                    temp = temp->next;
                    free(toDelete);
                }
            }
            free(graph->array);
        }
        free(graph);
    }
}

int main()
{
    // 创建有5个顶点的图
    int V = 5;
    struct Graph *graph = createGraph(V);

    // 添加边
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // 打印图
    printGraph(graph);

    // 释放内存
    freeGraph(graph);

    return 0;
}