/*
 * AVL树实现 - 自平衡二叉搜索树
 * 
 * AVL树是一种自平衡的二叉搜索树，由Adelson-Velsky和Landis在1962年发明。
 * 它保证任何节点的左右子树高度差不超过1，从而确保O(log n)的查找、插入和删除时间复杂度。
 * 
 * 特性：
 * - 每个节点都有一个平衡因子（左子树高度 - 右子树高度）
 * - 平衡因子只能是-1、0或1
 * - 当插入或删除导致不平衡时，通过旋转操作恢复平衡
 */

#include <stdlib.h>
#include <stdio.h>
// #include "avl.h"

/**
 * AVL树节点结构
 * 
 * @param val 节点存储的整数值
 * @param left 指向左子节点的指针
 * @param right 指向右子节点的指针  
 * @param parent 指向父节点的指针（便于某些操作）
 * @param height 以该节点为根的子树的高度
 */
typedef struct node
{
    int val;                // 节点值
    struct node *left;      // 左子节点
    struct node *right;     // 右子节点
    struct node *parent;    // 父节点
    int height;             // 节点高度
} node_t;

/**
 * 获取节点高度的函数
 * 
 * 注意：修复了原来的bug，应该是 node == NULL ? 0 : node->height
 * 空节点的高度定义为0，非空节点返回其存储的高度值
 * 
 * @param node 要查询高度的节点指针
 * @return 节点高度，空节点返回0
 */
static inline int height(node_t *node)
{
    return node == NULL ? 0 : node->height;  // 修复了原来的bug
}

/**
 * 更新节点的高度值
 * 
 * 节点的高度等于其左右子树高度的最大值加1
 * 叶子节点的高度为1，空节点的高度为0
 * 
 * @param node 要更新高度的节点指针
 */
void update_height(node_t *node)
{
    if (node)
    {
        int left_height = height(node->left);   // 获取左子树高度
        int right_height = height(node->right); // 获取右子树高度
        // 当前节点高度 = max(左子树高度, 右子树高度) + 1
        node->height = (left_height > right_height ? left_height : right_height) + 1;
    }
}

/**
 * 右旋操作（顺时针旋转）
 * 
 * 用于处理左-左不平衡情况，将左子节点提升为新的根节点
 * 
 * 旋转前:     y          旋转后:     x
 *           /  \                    /  \
 *          x    C                 A    y
 *         / \            =>            / \
 *        A   B                       B   C
 * 
 * @param y 需要右旋的节点（原根节点）
 * @return 新的根节点x
 */
node_t *rotate_right(node_t *y)
{
    node_t *x = y->left;        // x成为新的根节点
    y->left = x->right;         // y的左子树变为x的右子树
    if (x->right)
        x->right->parent = y;   // 更新父指针
    x->right = y;               // y成为x的右子节点
    x->parent = y->parent;      // x继承y的父节点
    y->parent = x;              // y的父节点变为x
    
    // 先更新y的高度，再更新x的高度（因为x现在是y的父节点）
    update_height(y);
    update_height(x);
    return x;                   // 返回新的根节点
}

/**
 * 左旋操作（逆时针旋转）
 * 
 * 用于处理右-右不平衡情况，将右子节点提升为新的根节点
 * 
 * 旋转前:   x              旋转后:       y
 *         /  \                        /  \
 *        A    y                     x    C
 *            / \          =>        / \
 *           B   C                 A   B
 * 
 * @param x 需要左旋的节点（原根节点）
 * @return 新的根节点y
 */
node_t *rotate_left(node_t *x)
{
    node_t *y = x->right;       // y成为新的根节点
    x->right = y->left;         // x的右子树变为y的左子树
    if (y->left)
        y->left->parent = x;    // 更新父指针
    y->left = x;                // x成为y的左子节点
    y->parent = x->parent;      // y继承x的父节点
    x->parent = y;              // x的父节点变为y
    
    // 先更新x的高度，再更新y的高度（因为y现在是x的父节点）
    update_height(x);
    update_height(y);
    return y;                   // 返回新的根节点
}

/**
 * 计算节点的平衡因子
 * 
 * 平衡因子 = 左子树高度 - 右子树高度
 * 
 * AVL树的平衡条件：
 * - 平衡因子 = -1：右子树比左子树高1
 * - 平衡因子 = 0：左右子树等高
 * - 平衡因子 = 1：左子树比右子树高1
 * - |平衡因子| > 1：树不平衡，需要旋转
 * 
 * @param node 要计算平衡因子的节点
 * @return 平衡因子值
 */
int balance_factor(node_t *node)
{
    return height(node->left) - height(node->right);
}

/**
 * AVL树插入操作
 * 
 * 在AVL树中插入新节点，并通过旋转操作维持树的平衡性
 * 
 * 插入步骤：
 * 1. 按照二叉搜索树的规则递归插入节点
 * 2. 更新路径上所有节点的高度
 * 3. 检查平衡因子，如果不平衡则进行相应的旋转操作
 * 
 * 四种不平衡情况及其处理方法：
 * - LL（左-左）：对根节点进行右旋
 * - RR（右-右）：对根节点进行左旋
 * - LR（左-右）：先对左子节点左旋，再对根节点右旋
 * - RL（右-左）：先对右子节点右旋，再对根节点左旋
 * 
 * @param root 当前子树的根节点
 * @param val 要插入的值
 * @return 插入后的子树根节点
 */
node_t *avl_insert(node_t *root, int val)
{
    // 1. 标准的BST插入操作
    if (!root)
    {
        // 创建新节点（递归基础情况）
        node_t *newnode = (node_t *)malloc(sizeof(node_t));
        newnode->val = val;
        newnode->left = newnode->right = newnode->parent = NULL;
        newnode->height = 1;  // 新节点的高度为1
        return newnode;
    }

    // 递归插入到相应的子树
    if (val < root->val)
    {
        root->left = avl_insert(root->left, val);
        root->left->parent = root;  // 更新父指针
    }
    else if (val > root->val)
    {
        root->right = avl_insert(root->right, val);
        root->right->parent = root; // 更新父指针
    }
    else
    {
        // 值已存在，不插入重复值
        return root;
    }

    // 2. 更新当前节点的高度
    update_height(root);

    // 3. 获取平衡因子并检查是否需要旋转
    int balance = balance_factor(root);

    // 左-左情况（LL）：新节点插入到左子树的左子树
    // 平衡因子 > 1 且新值小于左子节点的值
    if (balance > 1 && val < root->left->val)
    {
        return rotate_right(root);
    }

    // 右-右情况（RR）：新节点插入到右子树的右子树
    // 平衡因子 < -1 且新值大于右子节点的值
    if (balance < -1 && val > root->right->val)
    {
        return rotate_left(root);
    }

    // 左-右情况（LR）：新节点插入到左子树的右子树
    // 平衡因子 > 1 且新值大于左子节点的值
    if (balance > 1 && val > root->left->val)
    {
        root->left = rotate_left(root->left);   // 先左旋左子节点
        return rotate_right(root);              // 再右旋根节点
    }

    // 右-左情况（RL）：新节点插入到右子树的左子树
    // 平衡因子 < -1 且新值小于右子节点的值
    if (balance < -1 && val < root->right->val)
    {
        root->right = rotate_right(root->right); // 先右旋右子节点
        return rotate_left(root);                // 再左旋根节点
    }

    // 如果树已经平衡，直接返回根节点
    return root;
}

/**
 * 在AVL树中查找指定值
 * 
 * @param root 树的根节点
 * @param val 要查找的值
 * @return 找到的节点指针，未找到返回NULL
 */
node_t *avl_search(node_t *root, int val)
{
    if (root == NULL || root->val == val)
        return root;
    
    if (val < root->val)
        return avl_search(root->left, val);
    else
        return avl_search(root->right, val);
}

/**
 * 中序遍历AVL树（递归实现）
 * 输出结果是有序的
 * 
 * @param root 树的根节点
 */
void inorder_traversal(node_t *root)
{
    if (root != NULL)
    {
        inorder_traversal(root->left);   // 遍历左子树
        printf("%d ", root->val);        // 访问根节点
        inorder_traversal(root->right);  // 遍历右子树
    }
}

/**
 * 释放AVL树的所有节点内存
 * 
 * @param root 树的根节点
 */
void free_avl_tree(node_t *root)
{
    if (root != NULL)
    {
        free_avl_tree(root->left);   // 释放左子树
        free_avl_tree(root->right);  // 释放右子树
        free(root);                  // 释放当前节点
    }
}

/**
 * 打印树的结构（用于调试）
 * 
 * @param root 树的根节点
 * @param space 当前层的缩进空格数
 */
void print_tree(node_t *root, int space)
{
    const int COUNT = 10;  // 每层缩进的空格数
    
    if (root == NULL)
        return;
    
    space += COUNT;
    
    // 先打印右子树
    print_tree(root->right, space);
    
    // 打印当前节点
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d(h:%d)\n", root->val, root->height);
    
    // 再打印左子树
    print_tree(root->left, space);
}

/**
 * 简单的测试函数
 */
void test_avl_tree()
{
    node_t *root = NULL;
    
    printf("=== AVL树测试 ===\n");
    
    // 插入一系列值
    int values[] = {10, 20, 30, 40, 50, 25};
    int n = sizeof(values) / sizeof(values[0]);
    
    printf("插入序列: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", values[i]);
        root = avl_insert(root, values[i]);
    }
    printf("\n\n");
    
    printf("树的结构:\n");
    print_tree(root, 0);
    printf("\n");
    
    printf("中序遍历结果: ");
    inorder_traversal(root);
    printf("\n\n");
    
    // 测试查找
    int search_val = 25;
    node_t *found = avl_search(root, search_val);
    if (found)
        printf("找到值 %d，高度为 %d\n", search_val, found->height);
    else
        printf("未找到值 %d\n", search_val);
    
    // 释放内存
    free_avl_tree(root);
    printf("\n内存已释放\n");
}

/**
 * 主函数 - 演示AVL树的使用
 */
int main()
{
    test_avl_tree();
    return 0;
}