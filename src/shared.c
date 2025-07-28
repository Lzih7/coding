#include<stdio.h>
//定义节点类型
typedef struct _node {
    int data;           //数据域
    struct _node *next; //指针域
} node;
 
//定义单链表类型
typedef struct {
    node *head;      //头指针
    unsigned len;    //链表中的节点数量
} list;

int list_share(list *La,list *Lb){
    if(La==NULL||Lb==NULL) return 0;
    node pa=La->head;
    node pb=Lb->head;
    int lenA=0,lenB=0;
    while(pa!=NULL){
        pa=pa->next;
        lenA++;
    }
    while(pb!=NULL){
        pb=pb->next;
        lenB++;
    }
    if(pa!=pb) return 0;
    if(lenA>lenB){
        for(int i=0;i<lenA-lenB;i++){
            pa=pa->next;
        }
    }else{
        for(int i=0;i<lenB-lenA;i++){
            pb=pb->next;
        }
    }
    while(pa!=pb){
        pa=pa->next;
        pb=pb->next;
    }
    int cnt=0;
    while(pa!=NULL){
        pa=pa->next;
        cnt++;
    }
    return cnt;
}