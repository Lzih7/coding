void InOrder(BiTree root, CALLBACK Visit) { /* 中序遍历二叉树的非递归算法 */
    Stack s, *S = &s;
    BiTree p;

    InitStack(&S);

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

void PostOrder(BiTree root, CALLBACK Visit) {
    BiTNode *p, *q;
    Stack s, *S = &s;

    q = NULL;
    p = root;

    InitStack(&S);

    //TODO
    while (p != NULL || !IsEmpty(S)) {
        if (p != NULL) {
            Push(S, p);
            p = p->LChild;
        } else {
            GetTop(S, &p);
            if (p->RChild == NULL || p->RChild == q) {
                Visit(p->data);
                q = p;
                Pop(S, &p);
                p = NULL;
            } else
                p = p->RChild;
        }
    }

    ClearStack(S);
}
