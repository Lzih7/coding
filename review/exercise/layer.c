#include <stdio.h>
#include <stdlib.h>

typedef struct csnode
{
    char data;
    struct csnode *first;
    struct csnode *sibling;
} csnode, *cstree;

/*
bool queue_enter(queue *Q, void *v); //数据v进队Q。参数Q是指向队列的指针，v的类型是任意类型指针。
void* queue_leave(queue *Q); //数据出队。该数据是函数的返回值，其类型是任意类型指针。
bool queue_empty(queue *Q);

void visit(cstree csnode);
*/

void layer(cstree root, queue *Q)
{
    if (root == NULL)
        return;
    queue_enter(Q, root);
    while (!queue_empty(Q))
    {
        cstree temp = queue_leave(Q);
        visit(temp);
        if (temp->first != NULL)
        {
            queue_enter(Q, temp->first);
            cstree p = temp->first;
            while (p->sibling != NULL)
            {
                queue_enter(Q, p->sibling);
                p = p->sibling;
            }
        }
    }
}