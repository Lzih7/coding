#include<stdio.h>

int f(int n){
    if(n==1) return 1;
    return n*f(n-1);
}

int main(){
    int n;
    scanf("%d",&n);
    double sum=1;
    for(int i=0;i<n;i++){
        sum+=(1.0/f(i+1));
    }
    printf("%lf",sum);
    return 0;
}
//别写%d写习惯了！