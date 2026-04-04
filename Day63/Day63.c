//Problem: Perform DFS starting from a given source vertex using recursion.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node* next;
};

struct node* adj[100];
int visited[100];

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

void dfs(int s)
{
    printf("%d ", s);
    visited[s] = 1;

    struct node* ptr = adj[s];

    while(ptr != NULL)
    {
        if(!visited[ptr->vertex])
            dfs(ptr->vertex);

        ptr = ptr->next;
    }
}

int main()
{
    int n, m, u, v, s;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        adj[i] = NULL;
        visited[i] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);

        addEdge(u, v);
        addEdge(v, u);  
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    printf("DFS Traversal: ");
    dfs(s);

    return 0;
}