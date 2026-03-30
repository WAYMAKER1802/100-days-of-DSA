//Problem Statement: Construct a binary tree from given preorder and inorder traversal arrays.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

int preIndex = 0;
struct node* newNode(int val)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}
int search(int inorder[], int start, int end, int value)
{
    for(int i = start; i <= end; i++)
        if(inorder[i] == value)
            return i;

    return -1;
}
struct node* buildTree(int preorder[], int inorder[], int start, int end)
{
    if(start > end)
        return NULL;

    struct node* root = newNode(preorder[preIndex++]);

    if(start == end)
        return root;

    int inIndex = search(inorder, start, end, root->data);

    root->left = buildTree(preorder, inorder, start, inIndex - 1);
    root->right = buildTree(preorder, inorder, inIndex + 1, end);

    return root;
}
void postorder(struct node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct node* root = buildTree(preorder, inorder, 0, n - 1);

    postorder(root);

    return 0;
}