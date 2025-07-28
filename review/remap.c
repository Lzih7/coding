#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
struct _seqlist{
    ElemType elem[MAXSIZE];
    int last;
};
typedef struct _seqlist SeqList;

/*
The left ones are all odd numbers, and the right ones are all even numbers.
*/

void odd_even(SeqList *L) {
    if(L->last==0) return;
    ElemType tmp=0;
    int j=0;
    for(int i=0;i<=L->last;i++){
        if(L->elem[i]%2==1){
            if(i!=j){
                tmp=L->elem[j];
                L->elem[j]=L->elem[i];
                L->elem[i]=tmp;
            }
            j++;
        }
    }
}
//i number is odd, j must add at last, then if i==j, swap.
//if j!=i, j must be even number.