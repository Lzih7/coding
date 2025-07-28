#include<stdio.h>
#include<stdlib.h>

typedef struct node { //链表结点类型定义
    int data;
    struct node *next;
} node;
 
typedef struct { //采用头结点模式的链表类型定义
    node head;  //头结点
    int length; //链表长度（即结点数量）
} mlist;

void swap_node(node* prev){
    if(prev==NULL||prev->next==NULL||prev->next->next==NULL) return;
    node* cur=prev->next;
    node* nex=cur->next;
    prev->next=nex;
    cur->next=nex->next;
    nex->next=cur;
}

void list_sort(mlist *L){
    int len=L->length;  //unused
    node* head=L->head;
    node* cur=head;
    node* tmp=NULL;
    while(tmp!=head->next){
        for(;cur->next->next!=tmp;cur=cur->next){
            if(cur->next->data>cur->next->next->data) swap_node(cur);
        }
        tmp=cur->next;
        cur=head;
    }
    return;
}
/*for (int i = 0; i < len - 1; ++i) {
    cur = head;
    for (int j = 0; j < len - 1 - i; ++j) {
        if (cur->next->data > cur->next->next->data) {
            swap_node(cur);
        }
        cur = cur->next;
    }
}
*/