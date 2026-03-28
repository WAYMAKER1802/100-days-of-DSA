//Problem Statement:Check whether a given binary tree is symmetric around its center.
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int val)
{
    if(val == -1) return NULL;

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

int isMirror(struct node* a, struct node* b)
{
    if(a == NULL && b == NULL) return 1;

    if(a == NULL || b == NULL) return 0;

    return (a->data == b->data &&
            isMirror(a->left, b->right) &&
            isMirror(a->right, b->left));
}

int isSymmetric(struct node* root)
{
    if(root == NULL) return 1;
    return isMirror(root->left, root->right);
}

int main()
{
    int n, i;
    scanf("%d", &n);

    if(n == 0)
    {
        printf("YES");
        return 0;
    }

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

    if(isSymmetric(nodes[0]))
        printf("YES");
    else
        printf("NO");

    return 0;
}