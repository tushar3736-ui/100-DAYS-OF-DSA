// Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers (first list)
// - Third line: integer m
// - Fourth line: m space-separated integers (second list)

// Output:
// - Print the merged linked list elements, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 4
// 15 25 35 45

// Output:
// 10 15 20 25 30 35 40 45 50

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

struct Node* append(struct Node* tail, int value) {
    struct Node* node = createNode(value);
    if (tail != NULL) tail->next = node;
    return node;
}

struct Node* merge(struct Node* a, struct Node* b) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }

    if (a != NULL) tail->next = a;
    else tail->next = b;

    return dummy.next;
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct Node *head1 = NULL, *tail1 = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (head1 == NULL) {
            head1 = createNode(x);
            tail1 = head1;
        } else {
            tail1 = append(tail1, x);
        }
    }

    scanf("%d", &m);

    struct Node *head2 = NULL, *tail2 = NULL;
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        if (head2 == NULL) {
            head2 = createNode(x);
            tail2 = head2;
        } else {
            tail2 = append(tail2, x);
        }
    }

    struct Node* merged = merge(head1, head2);

    struct Node* cur = merged;
    while (cur != NULL) {
        printf("%d", cur->data);
        if (cur->next != NULL) printf(" ");
        cur = cur->next;
    }

    return 0;
}