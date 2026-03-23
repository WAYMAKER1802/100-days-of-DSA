//Problem Statement:Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.
#include <stdio.h>
#include <stdlib.h>

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
struct Node* insert(struct Node* root, int data) {
    if(root == NULL)
        return createNode(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}
struct Node* findLCA(struct Node* root, int n1, int n2) {

    if(root == NULL)
        return NULL;

    if(n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    if(n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    return root;
}

int main() {

    struct Node* root = NULL;
    int n, value, n1, n2;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter BST elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Enter two node values: ");
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);

    if(lca != NULL)
        printf("LCA = %d\n", lca->data);
    else
        printf("LCA not found\n");

    return 0;
}