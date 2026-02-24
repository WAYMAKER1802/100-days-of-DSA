//Problem: Delete First Occurrence of a Key - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    int n, key, x;
    struct Node *head = NULL, *ptr = NULL, *newnode = NULL;
    struct Node *prev = NULL, *curr = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        newnode = (struct Node *)malloc(sizeof(struct Node));
        newnode->data = x;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            ptr = head;
        } else {
            ptr->next = newnode;
            ptr = newnode;
        }
    }
    scanf("%d", &key);

    curr = head;
    if (head != NULL && head->data == key) {
        head = head->next;
        free(curr);
    } 
    else {
        while (curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr != NULL) {
            prev->next = curr->next;
            free(curr);
        }
    }

    ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}