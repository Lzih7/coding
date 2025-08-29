#include<stdio.h>

#define max(a,b) ((a>b)?a:b)

int backpack(int* val,int* wt,int n,int W){
    int dp[n+1][W+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0||j==0) dp[i][j]=0;
            else if(j>=wt[i-1]){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int main(){
    int val[3]={60,100,130};
    int wt[3]={10,20,30};
    int W=50;
    int n=sizeof(val)/sizeof(val[0]);
    int a=backpack(val,wt,n,W);
    printf("%d",a);

    return 0;
}