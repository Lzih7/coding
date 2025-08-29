#include<stdio.h>
/*
int main(){
    int yh[5][5]={0};
    for(int i=0;i<5;i++){
        yh[i][0]=1;
    }
    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            yh[i][j]=yh[i-1][j-1]+yh[i-1][j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<i+1;j++){
            if(yh[i][j]!=0){
                printf("%d ",yh[i][j]);
            }           
            if(j==i){
                printf("\n");
            }
        }
    }
    return 0;
}*/

int main(){
    int yh[5][5]={0};
    for(int i=0;i<5;i++){
        yh[i][0]=1;
    }
    for(int i=0;i<5;i++){
        for(int j=1;j<=i;j++){
            yh[i][j]=yh[i-1][j-1]+yh[i-1][j];
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<=i;j++){
            printf("%d\t",yh[i][j]);
        }
        putchar('\n');
    }
    return 0;
}