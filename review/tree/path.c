/*
 * 由于path函数的返回值为布尔类型，所以需要一个返回值为void的函数辅助实现
 * 利用found参数记录是否找到node
 */

#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

typedef struct Node{
    DataType data;
    struct Node* left;
    struct Node* right;
}BiTNode, *BiTree;

#define Stack_Size 50
typedef BiTNode* ElemType;
typedef struct{
    ElemType elem[Stack_Size];
    int top;
}Stack;

void init_stack(Stack *S); // 初始化栈
bool push(Stack* S, ElemType x); //x 入栈
bool pop(Stack* S, ElemType *px); //出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack* S, ElemType *px); //获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack* S);  // 栈为空时返回 true，否则返回 false

void traverse(BiTNode* root,BiTNode* node,Stack* s,bool* found){
    if(root==NULL) return;
    if(*found) return;
    push(s,root);
    if(root==node){
        *found=true;
        return;
    }
    traverse(root->left,node,s,found);
    traverse(root->right,node,s,found);
    if(*found) return; //出口处理
    BiTNode* temp;
    pop(s,&temp);
}
bool path(BiTNode* root, BiTNode* node, Stack* s){
    if(!root || !node || !s) return false; //关键的前提条件
    bool found=false;
    traverse(root,node,s,&found);
    return found;
}