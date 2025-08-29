#include<stdio.h>
#define fmax(a,b) ((a>b)?a:b)
#define fmin(a,b) ((a<b)?a:b)

int maxnum(int* arr,int n){
    int min=arr[0],max=arr[0];
 
    int max0=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>0){
           max=max(arr[i]*max,max);
           min=min(arr[i]*min,min);
        }
        else if(arr[i]<0){
            {
                int tmp;
                tmp=max;
                max=min;
                min=tmp;
            }
            max=max(arr[i]*max,max);
            min=min(arr[i]*min,min);

        }
        max0=fmax(max,max0);
    }
}