#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
struct _seqlist{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;

void del_dupnum(SeqList* L){
    int j=0;
    if(L->last==0) return;
    for(int i=1;i<=L->last;i++){
        if(L->elem[i]!=L->elem[j]){
            j++;
            L->elem[j]=L->elem[i];
        }
    }
    L->last=j;
}
//double pointer method