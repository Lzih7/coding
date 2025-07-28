#include<stdio.h>

void swap(int* a,int*b){
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

int partition(int* arr,int low,int high){
    int j=low-1;
    for(int i=low;i<high;i++){
        if(arr[i]<arr[high]){
            j++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[j+1],&arr[high]);
    return j+1;
}

void quickSort(int* arr,int low,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
 void printArray(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
 }

 int main(){
    int arr[10]={1,4,7,3,9,5,8,9,0,3};
    quickSort(arr,0,9);
    printArray(arr,10);

    return 0;
 }