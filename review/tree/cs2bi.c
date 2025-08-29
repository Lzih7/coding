#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* FirstChild;
    struct node* NextSibling;
}CSNode, *CSTree;

typedef struct binode{
    int data;
    struct binode* LChild;
    struct binode* RChild;
}BiTNode,*BiTree;

BiTree CS2Bi(CSTree rootCS) {
    if (rootCS == NULL) return NULL;
    
    BiTree rootBi = (BiTree)malloc(sizeof(BiTNode)); //生成一个新结点
    rootBi->data = rootCS->data;
    
    //TODO
    rootBi->LChild = CS2Bi(rootCS->FirstChild);
    rootBi->RChild = CS2Bi(rootCS->NextSibling);

    return rootBi;
}
/**
 * 测试函数：用于测试CS2Bi函数的正确性
 * 创建一个孩子兄弟表示的树，并将其转换为二叉树表示
 */
void testCS2Bi() {
    // 创建孩子兄弟树节点
    CSNode* csRoot = (CSNode*)malloc(sizeof(CSNode));
    CSNode* csChild1 = (CSNode*)malloc(sizeof(CSNode));
    CSNode* csChild2 = (CSNode*)malloc(sizeof(CSNode));
    CSNode* csChild3 = (CSNode*)malloc(sizeof(CSNode));
    CSNode* csGrandChild1 = (CSNode*)malloc(sizeof(CSNode));
    CSNode* csGrandChild2 = (CSNode*)malloc(sizeof(CSNode));
    
    // 初始化节点数据
    csRoot->data = 1;
    csChild1->data = 2;
    csChild2->data = 3;
    csChild3->data = 4;
    csGrandChild1->data = 5;
    csGrandChild2->data = 6;
    
    // 构建孩子兄弟树结构
    //       1
    //     / | \
    //    2  3  4
    //   / \    |
    //  5   6   7
    csRoot->FirstChild = csChild1;
    csRoot->NextSibling = NULL;
    
    csChild1->FirstChild = csGrandChild1;
    csChild1->NextSibling = csChild2;
    
    csChild2->FirstChild = NULL;
    csChild2->NextSibling = csChild3;
    
    csChild3->FirstChild = NULL;
    csChild3->NextSibling = NULL;
    
    csGrandChild1->FirstChild = NULL;
    csGrandChild1->NextSibling = csGrandChild2;
    
    csGrandChild2->FirstChild = NULL;
    csGrandChild2->NextSibling = NULL;
    
    // 调用转换函数
    BiTree biRoot = CS2Bi(csRoot);
    
    // 输出结果（简单的输出验证）
    printf("转换后的二叉树根节点数据: %d\n", biRoot->data);
    if (biRoot->LChild) {
        printf("左子树根节点数据: %d\n", biRoot->LChild->data);
    }
    if (biRoot->RChild) {
        printf("右子树根节点数据: %d\n", biRoot->RChild->data);
    }
    
    // 释放内存
    free(csRoot);
    free(csChild1);
    free(csChild2);
    free(csChild3);
    free(csGrandChild1);
    free(csGrandChild2);
    
    // 注意：这里为了简化测试，没有完整释放二叉树内存
    // 在实际应用中需要递归释放所有节点
}

int main() {
    testCS2Bi();
    return 0;
}