//Problem Statement:Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.
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
void verticalTraversal(struct Node* root, int hd,
                       int min, int max,
                       int store[][MAX], int count[]) {

    if(root == NULL)
        return;

    store[hd - min][count[hd - min]++] = root->data;

    verticalTraversal(root->left, hd - 1, min, max, store, count);
    verticalTraversal(root->right, hd + 1, min, max, store, count);
}
void findRange(struct Node* root, int hd, int* min, int* max) {

    if(root == NULL)
        return;

    if(hd < *min) *min = hd;
    if(hd > *max) *max = hd;

    findRange(root->left, hd - 1, min, max);
    findRange(root->right, hd + 1, min, max);
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, 0, n);

    int min = 0, max = 0;

    findRange(root, 0, &min, &max);

    int width = max - min + 1;

    int store[MAX][MAX];
    int count[MAX] = {0};

    verticalTraversal(root, 0, min, max, store, count);

    for(int i = 0; i < width; i++) {
        for(int j = 0; j < count[i]; j++)
            printf("%d ", store[i][j]);
        printf("\n");
    }

    return 0;
}