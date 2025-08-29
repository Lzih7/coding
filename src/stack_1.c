/*
 * 完成人　：刘梓涵(2024090911009)
 * 完成时间：2024-11-24, Sun, 20:13:54
 * 系统评分：96 未处理一个元素的情况
 * 记住：top++,--top
 */

/*关于push,pull中top的问题：top永远指向无效的位置*/
#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
int top = 0;


void stack_overflow(void)
{
  printf("Stack overflow\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
  printf("Stack underflow\n");
  exit(EXIT_FAILURE);
}


void make_empty(void)
{
  top = 0;
}

bool is_empty(void)
{
  return top == 0;
}

bool is_full(void)
{
  return top == STACK_SIZE;
}

void push(char ch)
{
  if (is_full())
    stack_overflow();
  else
    contents[top++] = ch;
}  //top为永远为‘空’

char pop(void)
{
  if (is_empty())
    stack_underflow();
  else
    return contents[--top];

  return '\0'; /* prevents compiler warning due to stack_underflow() call */
}  //pop的元素暂时还存在

int matched(char left,char right){
    return (left=='('&&right==')')||(left=='['&&right==']')||(left=='{'&&right=='}');
}

int balanced(char* ch){
    for(int i=0;i<STACK_SIZE&&ch[i]!='\0';i++){
        if(ch[i]=='('||ch[i]=='['||ch[i]=='{'){
            push(ch[i]);
        }
        else if(ch[i]==')'||ch[i]==']'||ch[i]=='}'){
            if(is_empty()) return 0;
            char topchar=pop();
            if(!matched(topchar,ch[i])) return 0;
        }
    }
    return 1;
}
int main(void)
{
    char ch[STACK_SIZE];

	fgets(ch,100,stdin);
	if( balanced(ch)) printf("Parentheses/braces are nested properly");
	else printf("Parentheses/braces are NOT nested properly");
	
	return 0;
}