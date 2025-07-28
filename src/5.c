#include<stdio.h>
#include<string.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n-1];
    int i=0;
    int j;
    int a=arr[0]&arr[1];
    for(;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=1;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a<arr[i]&arr[j]){
                a=arr[i]&arr[j];
            }
            
        }
    }
    printf("%d",a);

    return 0;
}