//Problem: Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *ptr = NULL, *newnode;
    int n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            ptr = newnode;
        } else {
            ptr->next = newnode;
            ptr = newnode;
        }
    }

    ptr->next = head;

    ptr = head;
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);

    return 0;
}