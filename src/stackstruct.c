#include<stdio.h>
#include<stdlib.h>

#define MAX_LENTH 100

typedef struct Stack{
    int top;
    int arr[MAX_LENTH];
}Stack;

Stack* createstack(void){
    Stack* stack=(Stack*)malloc(sizeof(Stack));  //动态分配空间，需深入理解
    stack->top=-1;

    return stack;
}

int isempty(void){
    return stack->top==-1;  //设为-1，与stack.c不同
}

int isfull(void){
    return stack->top==MAX_LENTH-1;  //需减1
}

void push(int val){
    if(isfull()){
        printf("overflow");
        return;  //用return退出函数
    }
    stack->top++;
    stack->arr[stack->top]=val;
}
