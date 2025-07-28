#include<stdio.h>

void push(stack *S, char x);    //将字符x压入栈S。S是指向栈的指针
char pop(stack *S);             //弹栈，返回S栈顶数据
bool empty(stack * S);          //测试栈S是否为空。如果为空，返回true，否则返回false

void reverse(){
    char c;
    c=gethchar();
    while(c!='.'){
        push(S,c);
        c=getchar();
    }
    while(!empty(S)){
        char x=pop(S);
        if(x!='.'){
            putchar(x);
        }
    }
    return;
}