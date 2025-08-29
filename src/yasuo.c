#include<stdio.h>

void printarray(int arr[],int numssize){
    for(int i=0;i<numssize;i++){
        printf("%d ",arr[i]);
    }
    return;
}
int main(){
    int arr[4][4]={
        {1,0,0,0},
        {2,3,0,0},
        {4,5,6,0},
        {7,8,9,10}
    };
    int ans[15]={0};
    int index=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<=i;j++){
            ans[index++]=arr[i][j];
        }
    }
    index--;
    printarray(ans,index);

    return 0;
}