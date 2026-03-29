//Problem Statement: Convert a binary tree into its mirror image by swapping left and right children at every node.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node* newNode(int val)
{
    if(val == -1)
        return NULL;

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void mirror(struct node* root)
{
    if(root == NULL)
        return;

    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}
void inorder(struct node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{
    int n, i;
    scanf("%d", &n);

    if(n == 0)
        return 0;

    int arr[n];
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct node* nodes[n];

    for(i = 0; i < n; i++)
        nodes[i] = newNode(arr[i]);

    for(i = 0; i < n; i++)
    {
        if(nodes[i] != NULL)
        {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left < n)
                nodes[i]->left = nodes[left];

            if(right < n)
                nodes[i]->right = nodes[right];
        }
    }

    struct node* root = nodes[0];

    mirror(root);

    inorder(root);

    return 0;
}