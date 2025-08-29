#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
struct _lnklist{
    ElemType data;
    struct _lnklist *next;
};

typedef struct _lnklist Node;
typedef struct _lnklist *LinkList;
/*
int lnk_search(LinkList L,int k,ElemType* p_ele){
    int len=0;
    Node* work=L;
    while(work->next){
        len++;
        work=work->next;
    }
    work=L;
    int pos=len-k+1;
    if(pos<=0) return 0;
    for(int i=0;i<pos;i++, work=work->next);
    *p_ele=work->data;
    return 1;
}*/

/*
快慢指针法
*/
int lnk_search(LinkList L,int k,ElemType* p_ele){
    Node* slow=L,*fast=L;
    for(int i=0;i<k;i++){
        fast=fast->next;
        if(!fast) return 0;
    }
    if(!fast || p_ele) return 0;
    while(fast){
        slow=slow->next;
        fast=fast->next;
    }
    *p_ele=slow->data;
    return 1;
}
