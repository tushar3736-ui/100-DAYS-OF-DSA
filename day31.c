#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
        return;
    stack[++top] = x;
}

void pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("%d\n", stack[top--]);
}

void display()
{
    if (top == -1)
        return;
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main()
{
    int n, op, val;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &op);

        if (op == 1)
        {
            scanf("%d", &val);
            push(val);
        }
        else if (op == 2)
        {
            pop();
        }
        else if (op == 3)
        {
            display();
        }
    }

    return 0;
}