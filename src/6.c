#include<stdio.h>

int main(){
    int a[10]={1,5,2,7,9,4,57};
    int i=0;
    int p=0;
    while(i<10){
        p=(a[i]<p)?p:a[i];
        i++;
    }
    printf("%d\n",p);
    for(i=0;i<10;i++){
        if(a[i]==p){
            printf("%d\n",i);
        }
    }

    return 0;

}