//Problem: Implement BFS and DFS Traversal of a Graph Using Adjacency Matrix
#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

// Queue for BFS
int queue[MAX], front = -1, rear = -1;

// Insert into queue
void enqueue(int v)
{
    if(rear == MAX - 1)
        return;
    if(front == -1)
        front = 0;
    queue[++rear] = v;
}

// Remove from queue
int dequeue()
{
    if(front == -1)
        return -1;

    int item = queue[front];

    if(front == rear)
        front = rear = -1;
    else
        front++;

    return item;
}

// BFS Traversal
void BFS(int start)
{
    int i;
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while(front != -1)
    {
        int node = dequeue();
        printf("%d ", node);

        for(i = 0; i < n; i++)
        {
            if(adj[node][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

// DFS Traversal
void DFS(int start)
{
    printf("%d ", start);
    visited[start] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[start][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

// Reset visited array
void resetVisited()
{
    for(int i = 0; i < n; i++)
        visited[i] = 0;
}

int main()
{
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    resetVisited();
    BFS(start);

    resetVisited();
    printf("\nDFS Traversal: ");
    DFS(start);

    return 0;
}