#include<stdio.h>

int* find(int* a,int n,int key){
    int *l,*r,*m;
    l=a;
    r=a+n-1;
    while(l<=r){
        m=l+(r-l)/2;
        if(*m==key) return m;
        else if(*m<key){
            r=m-1;
        }else{
            l=m+1;
        }
    }
    return NULL;
}
int main(){
    
}