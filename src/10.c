#include<stdio.h>

#define N 10

void swap(int*a,int*b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int main(){
    int a[N]={0,1,2,3,4,5,6,7,8,9};

    for(int i=0;i<N;++i)
        printf("%d",a[i]);
    putchar('\n');

    int *p=a;
    int i=N-1;
    while(i>=1){
        swap(p,p+i);
        i-=2;
        p++;
    }
    for(int i=0;i<N;++i){
        printf("%d",a[i]);
    }
    putchar('\n');

    return 0;
}