#include <stdio.h>
#include <stdlib.h>

#define Stack_Size 50
typedef BiTNode *ElemType;
typedef struct
{
    ElemType elem[Stack_Size];
    int top;
} Stack;

void init_stack(Stack *S);        // 初始化栈
bool push(Stack *S, ElemType x);  // x 入栈
bool pop(Stack *S, ElemType *px); // 出栈，元素保存到px所指的单元，函数返回true,栈为空时返回 false
bool top(Stack *S, ElemType *px); // 获取栈顶元素，将其保存到px所指的单元，函数返回true，栈满时返回 false
bool is_empty(Stack *S);          // 栈为空时返回 true，否则返回 false

typedef int DataType;

typedef struct Node
{
    DataType data;
    struct Node *left;
    struct Node *right;
} BiTNode, *BiTree;

void visit_node(BiTNode *node);

void preorder(BiTree root)
{
    if (!root)
        return;
    Stack *stk = (Stack *)malloc(sizeof(Stack));
    init_stack(stk);
    push(stk, root);
    while (!is_empty(stk))
    {
        BiTree temp = NULL;
        pop(stk, &temp);
        visit_node(temp);
        if (temp->left)
            push(stk, temp->left);
        if (temp->right)
            push(stk, temp->right);
    }
}