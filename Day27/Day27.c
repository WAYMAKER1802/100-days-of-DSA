//Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int);
struct Node* createList(int);
struct Node* findIntersection(struct Node*, struct Node*);

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* createList(int n) {
    struct Node *head = NULL, *tail = NULL;
    int value, i;

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

struct Node* findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* ptr1 = head1;
    struct Node* ptr2;

    while (ptr1 != NULL) {
        ptr2 = head2;
        while (ptr2 != NULL) {
            if (ptr1->data == ptr2->data) {
                return ptr1;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return NULL;
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    struct Node* intersection = findIntersection(head1, head2);

    if (intersection != NULL) {
        printf("%d", intersection->data);
    } else {
        printf("No Intersection");
    }

    return 0;
}