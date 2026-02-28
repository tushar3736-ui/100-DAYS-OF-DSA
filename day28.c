// Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the circular linked list elements starting from head, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void createCircularList(struct Node** head, int n) {
    int value;
    struct Node *temp = NULL, *last = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        temp = createNode(value);

        if (*head == NULL) {
            *head = temp;
            last = temp;
        } else {
            last->next = temp;
            last = temp;
        }
    }

    if (last != NULL)
        last->next = *head;
}

void traverse(struct Node* head) {
    if (head == NULL)
        return;

    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int n;
    struct Node* head = NULL;

    scanf("%d", &n);
    createCircularList(&head, n);
    traverse(head);

    return 0;
}