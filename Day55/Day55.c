//Problem Statement:
//Print the nodes visible when the binary tree is viewed from the right side.
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* buildTree(int arr[], int i, int n) {
    if(i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);

    root->left = buildTree(arr, 2*i + 1, n);
    root->right = buildTree(arr, 2*i + 2, n);

    return root;
}

void rightView(struct Node* root) {

    if(root == NULL)
        return;

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear) {

        int size = rear - front;

        for(int i = 0; i < size; i++) {

            struct Node* temp = queue[front++];

        
            if(i == size - 1)
                printf("%d ", temp->data);

            if(temp->left)
                queue[rear++] = temp->left;

            if(temp->right)
                queue[rear++] = temp->right;
        }
    }
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, 0, n);

    rightView(root);

    return 0;
}