// Problem Statement:
// Implement a Queue using a linked list supporting enqueue and dequeue operations.

// Input Format:
// - First line contains integer N
// - Next N lines contain queue operations

// Output Format:
// - Print dequeued elements
// - Print -1 if dequeue is attempted on an empty queue

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node* next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue()
{
    if(front == NULL)
        return -1;

    int val = front->data;
    struct node* temp = front;

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
    return val;
}

int main()
{
    int n, x;
    char op[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if(strcmp(op, "enqueue") == 0)
        {
            scanf("%d", &x);
            enqueue(x);
        }
        else if(strcmp(op, "dequeue") == 0)
        {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}