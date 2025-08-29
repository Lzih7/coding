#include<stdio.h>
#define max(a,b) ((a>b)?a:b)
int LIS(int *arr,int n){
    int dp[n];
    for(int i=0;i<n;i++) dp[i]=1;
    int maxnum=0;  //数据的保存很重要
    for(int i=0;i<=n-1;i++){
        for(int j=0;j<=i;j++){
            if(arr[i]>arr[j]){
                dp[i]=max(dp[j]+1,dp[i]);
            }
            maxnum=max(dp[i],maxnum);
        
        }
    }
    return maxnum;
}

int main(){
    int arr[10]={1,5,3,8,5,9,3,0,4,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max=LIS(arr,n);
    printf("%d",max);

    return 0;
}