// Problem Statement:
// Given a queue of integers, reverse the queue using a stack.

// Input Format:
// - First line contains integer N
// - Second line contains N space-separated integers

// Output Format:
// - Print the reversed queue

// Example:
// Input:
// 5
// 10 20 30 40 50


#include <stdio.h>

#define MAX 100

int main() {
    int n, i;
    int queue[MAX], stack[MAX];
    int top = -1;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    for(i = 0; i < n; i++) {
        top++;
        stack[top] = queue[i];
    }

    for(i = 0; i < n; i++) {
        queue[i] = stack[top];
        top--;
    }

    for(i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}