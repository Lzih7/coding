/*
only one pointer to the tail of the linklist.
*/

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct _QueueNode {
    ElemType data;          // 数据域
    struct _QueueNode *next;      // 指针域
}LinkQueueNode, *LinkQueue;

bool init_queue(LinkQueue* LQ){
    *LQ=(LinkQueue*)malloc(sizeof(LinkQueue));
    if(*LQ==NULL) return false;
    *LQ->next=*LQ;
    return true;
} //LQ is a pointer to pointer.

bool enter_queue(LinkQueue* LQ,ELemType x){
    LinkQueueNode* newnode=(LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    if(newnode==NULL) return true;
    newnode->data=x;
    newnode->next=(*LQ)->next;
    (*LQ)->next=newnode;
    (*LQ)=(*LQ)->next;
    return true;
}

bool leave_queue(LinkQueue* LQ,ElemType* x){
    if(*LQ->next=*LQ) return false;
    LinkQueueNode* frontnode=*LQ->next->next;
    *x=frontnode->data;
    *LQ->next->next=frontnode->next;
    if(frontnode=*LQ){
        *LQ=*LQ->next;
    }
    free(frontnode);
    return true;
}
//p0->frontnode->...->LQ->p0, when it starts LQ equals to p0.