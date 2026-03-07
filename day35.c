// Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n (number of elements)
// - Second line: n space-separated integers

// Output:
// - Print queue elements from front to rear, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node *front=NULL,*rear=NULL;

void enqueue(int x){
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->data=x;
    newNode->next=NULL;

    if(rear==NULL){
        front=rear=newNode;
    }
    else{
        rear->next=newNode;
        rear=newNode;
    }
}

void display(){
    struct Node* temp=front;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){

    int n,x,i;

    scanf("%d",&n);

    for(i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(x);
    }

    display();

    return 0;
}