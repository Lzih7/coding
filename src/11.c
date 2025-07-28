#include<stdio.h>
#include<stdbool.h>

#define N 20

int main(){
    int a[N]={1,20,2,19,3,18,4,17,5,16,6,15,7,14,8,13,9,12,10,11};
    int key;
    scanf("%d",&key);

    bool found=false;

    int *p;
    int i=0;
    for(p=a;i+1<N;p++){
        
        if(*p==key){
            printf("%d",i);
            found=true;
            break;
        }
        i++;
    }




    return 0;
}