//Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

struct poly {
    int coeff;
    int exp;
    struct poly *next;
};

struct poly* insertTerm(struct poly *head, int c, int e) {
    struct poly *newNode = (struct poly*)malloc(sizeof(struct poly));
    struct poly *ptr = head;

    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newNode;
    return head;
}

void display(struct poly *head) {
    struct poly *ptr = head;

    while (ptr != NULL) {
        if (ptr->exp == 0)
            printf("%d", ptr->coeff);
        else if (ptr->exp == 1)
            printf("%dx", ptr->coeff);
        else
            printf("%dx^%d", ptr->coeff, ptr->exp);

        if (ptr->next != NULL)
            printf(" + ");

        ptr = ptr->next;
    }
}

int main() {
    int n, i, coeff, exp;
    struct poly *head = NULL;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = insertTerm(head, coeff, exp);
    }

    display(head);

    return 0;
}