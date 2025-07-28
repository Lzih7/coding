#include <stdlib.h>
#include <stdio.h>
// #include "avl.h"

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
    struct node *parent;
    int height;
} node_t;

// 内联函数，寻找树高
inline int height(node_t *node)
{
    return node == NULL ? node->height : 0;
}

// 更新树高
void update_height(node_t *node)
{
    if (node)
    {
        int left_height = height(node->left);
        int right_height = height(node->right);
        node->height = (left_height > right_height ? left_height : right_height) + 1;
    }
}

// 右旋，注意parent元素要更新！
node_t *rotate_right(node_t *y)
{
    node_t *x = y->left;
    y->left = x->right;
    if (x->right)
        x->right->parent = y;
    x->right = y;
    x->parent = y->parent;
    y->parent = x;
    update_height(y);
    update_height(x);
    return x;
}

// 左旋
node_t *rotate_left(node_t *x)
{
    node_t *y = x->right;
    x->right = y->left;
    if (y->left)
        y->left->parent = x;
    y->left = x;
    y->parent = x->parent;
    x->parent = y;
    update_height(x);
    update_height(y);
    return y;
}

// 寻找平衡常数
int balance_factor(node_t *node)
{
    return height(node->left) - height(node->right);
}

node_t *avl_insert(node_t *root, int val)
{
    if (!root)
    {
        // 创造新节点，root为空时
        node_t *newnode = (node_t *)malloc(sizeof(node_t));
        newnode->val = val;
        newnode->left = newnode->right = newnode->parent = NULL;
        newnode->height = 1;
        return newnode;
    }

    if (val < root->val)
    {
        root->left = avl_insert(root->left, val);
        root->left->parent = root;
    }
    else if (val > root->val)
    {
        root->right = avl_insert(root->right, val);
        root->right->parent = root;
    }
    else
    {
        return root;
    }

    // 2. 更新高度
    update_height(root); // 每一层都会更新，形成递归

    // 3. 检查平衡并旋转
    int balance = balance_factor(root);

    // 左左情况
    if (balance > 1 && val < root->left->val)
    {
        return rotate_right(root);
    }

    // 右右情况
    if (balance < -1 && val > root->right->val)
    {
        return rotate_left(root);
    }

    // 左右情况
    if (balance > 1 && val > root->left->val)
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    // 右左情况
    if (balance < -1 && val < root->right->val)
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}