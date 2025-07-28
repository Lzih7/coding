#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};

typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;

void lnk_merge(LinkList A,LinkList B,LinkList C){
    Node* temp_a=A->next;
    Node* temp_b=B->next;
    Node* temp_c=C;
    int flag=1; //if flag==1, merge A, else merge B.
    while(temp_a && temp_b){
        if(flag==1){
            temp_c->next=temp_a;
            temp_a=temp_a->next;
            temp_c=temp_c->next;
            flag=0;
        }
        else{
            temp_c->next=temp_b;
            temp_b=temp_b->next;
            temp_c=temp_c->next;
            flag=1;
        }
    }
    temp_c->next=(temp_a)? temp_a :temp_b;

}