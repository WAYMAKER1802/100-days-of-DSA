//Problem Statement:Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.
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
struct Node* buildTree(int arr[], int i, int n) {
    if(i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, 2*i + 1, n);
    root->right = buildTree(arr, 2*i + 2, n);

    return root;
}
struct Node* findLCA(struct Node* root, int n1, int n2) {

    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    struct Node* left = findLCA(root->left, n1, n2);
    struct Node* right = findLCA(root->right, n1, n2);

    if(left != NULL && right != NULL)
        return root;

    return (left != NULL) ? left : right;
}

int main() {

    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter level-order traversal (-1 for NULL):\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, 0, n);

    int n1, n2;
    printf("Enter two node values: ");
    scanf("%d %d", &n1, &n2);

    struct Node* lca = findLCA(root, n1, n2);

    if(lca != NULL)
        printf("LCA = %d\n", lca->data);
    else
        printf("LCA not found\n");

    return 0;
}