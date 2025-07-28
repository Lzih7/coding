#include <stdio.h>
#include <stdlib.h>

bool del_vertex(ListGraph *G, VertexType v) {
    // 1. 检查顶点是否存在
    int v_pos = locate_vertex(G, v);
    if (v_pos == -1) return false;

    // 2. 删除所有指向该顶点的边（入边）
    for (int i = 0; i < G->vexnum; i++) {
        if (i == v_pos) continue; // 跳过待删除顶点

        ArcNode *prev = NULL;
        ArcNode *current = G->vertex[i].firstarc;

        while (current != NULL) {
            if (current->adjvex == v_pos) {
                // 删除这条边
                if (prev == NULL) {
                    G->vertex[i].firstarc = current->nextarc;
                } else {
                    prev->nextarc = current->nextarc;
                }
                ArcNode *to_free = current;
                current = current->nextarc;
                free(to_free);
                G->arcnum--;
            } else {
                // 调整后续顶点的索引
                if (current->adjvex > v_pos) {
                    current->adjvex--;
                }
                prev = current;
                current = current->nextarc;
            }
        }
    }

    // 3. 删除该顶点的所有出边
    ArcNode *arc = G->vertex[v_pos].firstarc;
    while (arc != NULL) {
        ArcNode *next = arc->nextarc;
        free(arc);
        G->arcnum--;
        arc = next;
    }
    G->vertex[v_pos].firstarc = NULL;

    // 4. 从顶点数组中移除该顶点，并调整后续顶点位置
    for (int i = v_pos; i < G->vexnum - 1; i++) {
        G->vertex[i] = G->vertex[i + 1];

        // 调整邻接表中受影响顶点的索引
        ArcNode *current = G->vertex[i].firstarc;
        while (current != NULL) {
            if (current->adjvex > v_pos) {
                current->adjvex--;
            }
            current = current->nextarc;
        }
    }

    G->vexnum--;
    return true;
}