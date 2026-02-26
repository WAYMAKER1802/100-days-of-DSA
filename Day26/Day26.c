//Problem: Doubly Linked List Insertion and Traversal - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

int main() {
    int n, i, val;
    struct Node *head = NULL, *temp = NULL, *newnode = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &val);

        newnode->data = val;
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}