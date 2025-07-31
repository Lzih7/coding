#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};
typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;

bool cmp(ElemType mink, ElemType maxk, ElemType num){
    return (num>mink && num<maxk);
}

void lnk_del_x2y(LinkList L, ElemType mink, ElemType maxk){
    Node* prev=L;
    Node* curr=prev->next; //curr point to the element need to de judged.
    while(curr){
        if(cmp(mink,maxk,curr->data)){
            Node* fr=curr;
            prev->next=curr->next; //the place prev pointed to is constantly changing, until curr says it is safe. 
            curr=curr->next;
            free(fr);
        }
        else{
            prev=curr;
            curr=curr->next;
        }
    }
}