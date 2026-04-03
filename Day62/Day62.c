//Problem: Build a graph with adjacency list representation. Use linked lists or dynamic arrays.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int vertex;
    struct node* next;
};
struct node* adj[100];
struct node* createNode(int v)
{
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->vertex = v;
    ptr->next = NULL;
    return ptr;
}
void addEdge(int u, int v)
{
    struct node* ptr = createNode(v);
    ptr->next = adj[u];
    adj[u] = ptr;
}
void display(int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("Vertex %d:", i);

        struct node* ptr = adj[i];

        while(ptr != NULL)
        {
            printf(" -> %d", ptr->vertex);
            ptr = ptr->next;
        }

        printf("\n");
    }
}
int main()
{
    int n, m, u, v, type;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter 1 for Directed Graph, 0 for Undirected Graph: ");
    scanf("%d", &type);

    for(int i = 0; i < m; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        addEdge(u, v);

        if(type == 0)
            addEdge(v, u);
    }

    printf("\nAdjacency List Representation:\n");
    display(n);

    return 0;
}