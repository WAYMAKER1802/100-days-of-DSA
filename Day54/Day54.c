//Problem Statement:Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed 
// left-to-right and right-to-left.
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
void zigzagTraversal(struct Node* root) {

    if(root == NULL)
        return;

    struct Node* queue[MAX];
    int front = 0, rear = 0;

    int leftToRight = 1;

    queue[rear++] = root;

    while(front < rear) {

        int size = rear - front;
        int level[size];

        for(int i = 0; i < size; i++) {

            struct Node* temp = queue[front++];

            int index = leftToRight ? i : size - 1 - i;
            level[index] = temp->data;

            if(temp->left)
                queue[rear++] = temp->left;

            if(temp->right)
                queue[rear++] = temp->right;
        }

        for(int i = 0; i < size; i++)
            printf("%d ", level[i]);

        leftToRight = !leftToRight; 
    }
}

int main() {

    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, 0, n);

    zigzagTraversal(root);

    return 0;
}