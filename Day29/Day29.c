//Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createList(int n) {
    struct node *head = NULL, *ptr = NULL, *newNode = NULL;
    int val, i;

    for (i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &val);

        newNode->data = val;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            ptr = newNode;
        } else {
            ptr->next = newNode;
            ptr = newNode;
        }
    }
    return head;
}

struct node* rotateRight(struct node *head, int k, int n) {
    struct node *ptr = head;
    int i;

    if (head == NULL || k == 0)
        return head;

    k = k % n;   
    if (k == 0)
        return head;

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = head;
    for (i = 1; i < n - k; i++)
        head = head->next;
    ptr = head->next;
    head->next = NULL;

    return ptr;
}

void display(struct node *head) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    int n, k;
    struct node *head = NULL;

    scanf("%d", &n);
    head = createList(n);
    scanf("%d", &k);

    head = rotateRight(head, k, n);
    display(head);

    return 0;
}