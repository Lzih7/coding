/*纯数组写法，未使用结构体*/

#include <stdio.h>
#include <stdbool.h>
#define STACK_SIZE 20

int stack[STACK_SIZE];
int top = 0;
void overflow()
{
    printf("overflow");
}

void underflow()
{
    printf("underflow");
}

bool fullstack()
{
    return top == STACK_SIZE;
}

bool emptystack()
{
    return top == 0;
}

void push(int i)
{
    if (fullstack())
    {
        overflow();
    }
    else
    {
        stack[top++] = i;
    }
}

int pop()
{
    if (emptystack())
    {
        underflow();
    }
    else
    {
        return stack[--top];
    }
}

int peek(void)
{
    return stack[top - 1];
}
int main()
{
    push(1);
    push(2);
    printf("%d\n", pop());
    printf("%d", peek());

    return 0;
}