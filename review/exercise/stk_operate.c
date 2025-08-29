#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
#define Stack_Size 50
typedef struct{
    ElemType elem[Stack_Size];
    int top;
}Stack;

bool push(Stack* S, ElemType x);
bool pop(Stack* S, ElemType *x);
void init_stack(Stack *S);

void init_stack(Stack *S){
    S->top = -1;
}

int compute_reverse_polish_notation(char *str){
    int ans;
    Stack* stk=(Stack*)malloc(sizeof(Stack));
    init_stack(stk);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]==' ') continue;
        int temp=0;
        int fst, sec;
        bool flag=false;
        while(str[i]>='0' && str[i]<='9'){
            flag=true;
            temp=temp*10+(str[i]-'0');
            i++;
        }
        if(flag){
            i--; //at last there's an extra i++.
            push(stk,temp);
        }
        if(str[i]=='*'){
            pop(stk,&sec);
            pop(stk,&fst);
            push(stk,fst*sec);
        }
        else if(str[i]=='/'){
            pop(stk,&sec);
            pop(stk,&fst);
            push(stk,fst/sec);
        }
        else if(str[i]=='+'){
            pop(stk,&sec);
            pop(stk,&fst);
            push(stk,fst+sec);
        }
        else if(str[i]=='-'){
            pop(stk,&sec);
            pop(stk,&fst);
            push(stk,fst-sec);
        }
        else if(str[i]=='%'){
            pop(stk,&sec);
            pop(stk,&fst);
            push(stk,fst%sec);
        }
    }
    pop(stk,&ans);
    return ans;
}