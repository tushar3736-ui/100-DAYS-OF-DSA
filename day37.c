// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete

#include<stdio.h>
#include<string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x){
    int i = size - 1;

    while(i >= 0 && pq[i] > x){
        pq[i+1] = pq[i];
        i--;
    }

    pq[i+1] = x;
    size++;
}

int delete(){
    if(size == 0)
        return -1;

    int val = pq[0];

    for(int i=1;i<size;i++)
        pq[i-1] = pq[i];

    size--;

    return val;
}

int peek(){
    if(size == 0)
        return -1;

    return pq[0];
}

int main(){

    int N;
    scanf("%d",&N);

    char op[10];
    int x;

    for(int i=0;i<N;i++){

        scanf("%s",op);

        if(strcmp(op,"insert")==0){
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"delete")==0){
            printf("%d\n",delete());
        }
        else if(strcmp(op,"peek")==0){
            printf("%d\n",peek());
        }
    }

    return 0;
}