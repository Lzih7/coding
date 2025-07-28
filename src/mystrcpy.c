#include<stdio.h>

void my_strcpy(const char* s,char* t){
    while(*s!='\0'){
        *t++=*s++;
    }
    *t='\0';
}

int main(){
    char* s="hjkdadds";
    char dest[50];
    my_strcpy(s,dest);
    printf("%s",dest);

    return 0;
}