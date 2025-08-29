#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
    int val;
    struct LNode *next;
} LNode, *LinkList;
LinkList newhead(int data)
{
    LinkList head = (LinkList)malloc(sizeof(LNode));
    head->val = data;
    head->next = NULL;
    return head;
}
LinkList inserHead(int a, LinkList head)
{
    LinkList newnode = (LinkList)malloc(sizeof(LNode));
    newnode->val = a;
    newnode->next = head->next;
    head->next = newnode;
    return head;
}
LinkList inserTail(int a,LinkList head)
{
    LinkList newnode = (LNode *)malloc(sizeof(LNode));
    LinkList temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->val = a;
    return head;
}
int main()
{
    int DATA1 = 1, DATA2 = 2, DATA3 = 3;
    LinkList head = newhead(1);
    head = inserHead(DATA3, head);
    head = inserHead(DATA2, head);
    head = inserHead(DATA1, head);
    head = inserTail(DATA1, head);
}