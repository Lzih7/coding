#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* FirstChild;
    struct node* NextSibling;
}CSNode, *CSTree;

typedef struct ninode{
    int data;
    struct binode* LChild;
    struct binode* RChild;
}BiNode,*BiTree;

BiTree CS2Bi(CSTree rootCS) {
    if (rootCS == NULL) return NULL;
    
    BiTree rootBi = (BiTree)malloc(sizeof(BiTNode)); //生成一个新结点
    rootBi->data = rootCS->data;
    
    //TODO
    rootBi->LChild = CS2Bi(rootCS->FirstChild);
    rootBi->RChild = CS2Bi(rootCS->NextSibling);

    return rootBi;
}