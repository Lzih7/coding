#include<stdio.h>

int main(){
    char c;
    int i=0;

    while((c=getchar())!='\n'){
        int j=c-'0';
        i=i*10+j;
    }

    printf("%d\n",i);

    return 0;
}