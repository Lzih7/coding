#include<stdio.h>
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int Common_Factor(int a,int b){
    while(b){
        a=a%b;
        swap(&a,&b);
    }
    return a;
}

int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d",Common_Factor(x,y));

    return 0;
}