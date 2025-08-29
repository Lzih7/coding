#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}node;

node* creatnode(int n){
    node* newnode=(node*)malloc(sizeof(newnode));
    newnode->val=n;
    newnode->next=NULL;

    return newnode;
}
node* insert(node* head,int n){
    node* newnode=creatnode(n);
    newnode->next=head->next;
    head->next=newnode;
    return newnode;
    head->val++;
}

int main(){
    printf("请输入三个整数：");
    int n1,n2,n3;
    scanf("%d %d %d",&n1,&n2,&n3);
    node* head=(node*)malloc(sizeof(node));
    head->next=NULL;
    head->val=0;
    insert(head,n3);
    insert(head,n2);
    insert(head,n1);
    printf("%d\t",head->next->val);
    printf("%d\t",head->next->next->val);
    printf("%d",head->next->next->next->val);
    return 0;
}