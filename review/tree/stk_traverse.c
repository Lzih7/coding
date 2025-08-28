void InOrder(BiTree root, CALLBACK Visit) { /* 中序遍历二叉树的非递归算法 */
    Stack s, *S = &s;
    BiTree p;

    InitStack(S);

    //TODO
    p = root;
    while (p != NULL || !IsEmpty(S)) {
        if (p != NULL) {
            Push(S, p);
            p = p->LChild;
        } else {
            Pop(S, &p);
            Visit(p->data);
            p = p->RChild;
        }
    }

    ClearStack(S);
}

/**
 * 后序遍历二叉树的非递归实现
 * @param root 二叉树的根节点指针
 * @param Visit 访问节点数据的回调函数指针
 * 
 * 该函数使用栈结构实现二叉树的后序遍历，遍历顺序为：左子树 -> 右子树 -> 根节点
 * 通过标记已访问的节点来避免重复访问
 */
void PostOrder(BiTree root, CALLBACK Visit) {
    BiTNode *p, *q;
    Stack s, *S = &s;

    q = NULL;
    p = root;

    InitStack(S);

    //TODO
    // 后序遍历的非递归实现主循环
    // 当前节点不为空或栈不为空时继续遍历
    while (p != NULL || !IsEmpty(S)) {
        if (p != NULL) {
            // 沿左子树向下访问，将路径上的节点入栈
            Push(S, p);
            p = p->LChild;
        } else {
            // 当前节点为空，从栈中取出节点进行处理
            GetTop(S, &p);
            // 判断右子树是否已访问完毕
            if (p->RChild == NULL || p->RChild == q) {
                // 访问当前节点数据
                Visit(p->data);
                // 标记当前节点为已访问
                q = p;
                // 弹出已处理完的节点
                Pop(S, &p);
                p = NULL;
            } else
                // 转向右子树进行遍历
                p = p->RChild;
        }
    }

    ClearStack(S);
}
