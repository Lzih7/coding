#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool is_mirror(char* s1,char* s2){
    char* p=s1, *q=s2;
    int len=strlen(s2);
    q+=(len-1);
    if(strlen(s1)!=strlen(s2)) return false;
    while(*p==*q){
        p++;
        q--;
        if(q==s2&&*q==*p) return true;
    }
    return false;
}

int main(){
    char* s1="asdfg";
    char* s2="gfdsa";
    if(is_mirror(s1,s2)) printf("true");
    else printf("false");

    return 0;
}
//bool类型，函数调用，移动判断