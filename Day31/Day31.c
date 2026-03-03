//Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Push operation */
void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = val;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d\n", stack[top]);
    top--;
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n, op, val, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &val);
            push(val);
        }
        else if (op == 2) {
            pop();
        }
        else if (op == 3) {
            display();
        }
    }

    return 0;
}