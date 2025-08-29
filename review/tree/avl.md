# AVL树实现

## 概述

AVL树是一种自平衡的二叉搜索树，由苏联数学家Adelson-Velsky和Landis在1962年发明。它是第一个被发明的自平衡二叉搜索树，通过在每次插入和删除操作后进行必要的旋转来维持树的平衡。

## 特性

- **平衡性**：任何节点的左右子树高度差不超过1
- **时间复杂度**：查找、插入、删除操作的时间复杂度均为O(log n)
- **空间复杂度**：O(n)
- **平衡因子**：每个节点的平衡因子为左子树高度减去右子树高度，值只能是-1、0或1

## 文件结构

```
avl.c - AVL树的完整实现
├── 节点结构定义
├── 高度相关函数
├── 旋转操作函数
├── 平衡因子计算
└── 插入操作
```

## 核心数据结构

```c
typedef struct node {
    int val;                // 节点值
    struct node *left;      // 左子节点
    struct node *right;     // 右子节点
    struct node *parent;    // 父节点
    int height;             // 节点高度
} node_t;
```

## 主要函数

### 1. 高度管理

- `height(node_t *node)` - 获取节点高度
- `update_height(node_t *node)` - 更新节点高度

### 2. 旋转操作

- `rotate_left(node_t *x)` - 左旋操作
- `rotate_right(node_t *y)` - 右旋操作

### 3. 平衡维护

- `balance_factor(node_t *node)` - 计算平衡因子
- `avl_insert(node_t *root, int val)` - 插入节点并维持平衡

### 4. 基本操作

- `avl_search(node_t *root, int val)` - 查找指定值
- `inorder_traversal(node_t *root)` - 中序遍历（输出有序序列）
- `free_avl_tree(node_t *root)` - 释放树的所有内存

### 5. 调试和测试

- `print_tree(node_t *root, int space)` - 打印树的结构
- `test_avl_tree()` - 完整的测试函数
- `main()` - 主函数，演示AVL树的使用

## 四种不平衡情况

### 1. 左-左（LL）情况
```
    z                y
   / \              / \
  y   T4    =>     x   z
 / \              / \ / \
x  T3           T1 T2 T3 T4
```
**解决方案**：对z进行右旋

### 2. 右-右（RR）情况
```
z                  y
 \                / \
  y       =>     z   x
 / \            / \ / \
T1  x         T1 T2 T3 T4
   / \
  T2 T3
```
**解决方案**：对z进行左旋

### 3. 左-右（LR）情况
```
  z               z              x
 / \             / \            / \
y  T4    =>     x  T4   =>     y   z
 \             /              / \ / \
  x           y             T1 T2 T3 T4
 / \         / \
 T2 T3     T1  T2
```
**解决方案**：先对y进行左旋，再对z进行右旋

### 4. 右-左（RL）情况
```
z               z                x
 \               \              / \
  y       =>      x      =>    z   y
 /               / \          / \ / \
x               T2  y       T1 T2 T3 T4
 \                  / \
  T2              T3  T4
```
**解决方案**：先对y进行右旋，再对z进行左旋

## 使用示例

### 基本使用

```c
#include <stdio.h>
#include <stdlib.h>
// 包含avl.c中的所有函数

int main() {
    node_t *root = NULL;
    
    // 插入节点
    root = avl_insert(root, 10);
    root = avl_insert(root, 20);
    root = avl_insert(root, 30);
    root = avl_insert(root, 40);
    root = avl_insert(root, 50);
    root = avl_insert(root, 25);
    
    // 打印树的结构
    printf("树的结构:\n");
    print_tree(root, 0);
    
    // 中序遍历（输出有序序列）
    printf("中序遍历: ");
    inorder_traversal(root);
    printf("\n");
    
    // 查找节点
    node_t *found = avl_search(root, 25);
    if (found) {
        printf("找到节点 25，高度为 %d\n", found->height);
    }
    
    // 释放内存
    free_avl_tree(root);
    
    return 0;
}
```

### 运行内置测试

代码中已经包含了一个完整的测试函数，直接编译运行即可看到演示效果：

```c
// 代码中的 main() 函数会调用 test_avl_tree()
// 展示插入、遍历、查找等完整功能
```

## 编译和运行

```bash
# 编译
gcc -o avl avl.c

# 运行
./avl
```

## 算法复杂度分析

| 操作 | 平均时间复杂度 | 最坏时间复杂度 | 空间复杂度 |
|------|----------------|----------------|------------|
| 查找 | O(log n)       | O(log n)       | O(1)       |
| 插入 | O(log n)       | O(log n)       | O(1)       |
| 删除 | O(log n)       | O(log n)       | O(1)       |

## 优缺点

### 优点
- 保证了最坏情况下O(log n)的查找时间
- 树的高度始终保持在log n级别
- 适合频繁查找的应用场景

### 缺点
- 每次插入和删除都可能需要进行旋转操作
- 相比普通BST，需要额外的存储空间来保存高度信息
- 实现相对复杂

## 注意事项

1. **Bug修复**：原代码中的`height`函数有一个bug，已在注释版本中修复
2. **内存管理**：示例代码中没有包含删除操作和内存释放，实际使用时需要添加
3. **父指针**：代码中维护了父指针，这在某些操作中很有用，但不是AVL树的必需部分

## 已实现功能

✅ **已完成的功能：**
- 插入操作（带自动平衡）
- 查找操作
- 中序遍历（获取有序序列）
- 树的可视化打印
- 内存释放函数
- 完整的测试用例

## 可扩展功能

🔄 **可以进一步添加的功能：**
- 删除操作（需要处理删除后的重新平衡）
- 前序和后序遍历
- 查找最小值和最大值节点
- 计算树的节点总数
- 验证AVL树性质的函数
- 从数组批量构建AVL树
- 序列化和反序列化功能

## 参考资料

- [AVL Tree - Wikipedia](https://en.wikipedia.org/wiki/AVL_tree)
- Introduction to Algorithms (CLRS)
- Data Structures and Algorithm Analysis in C (Mark Allen Weiss)