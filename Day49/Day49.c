//Problem: BST Insert
//Implement the solution for this problem.
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
void inorder(struct Node* root) {

    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {

    int n, value;
    struct Node* root = NULL;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Inorder traversal of BST:\n");
    inorder(root);

    return 0;
}