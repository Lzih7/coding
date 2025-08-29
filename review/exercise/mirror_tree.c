#include<stdio.h>
#include<stdlib.h>

struct _node{
    int val;
    struct _node* left;
    struct _node* right;
};
typedef struct _node node;
typedef node *bitree;
bitree mirror(node* root){
    if(root==NULL) return NULL;
    bitree left=mirror(root->right);
    bitree right=mirror(root->left);
    root->left=mirror(left);
    root->right=mirror(right);
    return root;
}