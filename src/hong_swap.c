#include<stdio.h>
#define swap(a,b){int tmp=a;a=b;b=tmp;}
/*
void swap(int* a,int* b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
*/
int main(){
    int x=1,y=5;
    //swap(&x,&y);
    swap(x,y);
    printf("%d,%d",x,y);

    return 0;
}