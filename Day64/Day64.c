//Problem: Perform BFS from a given source using queue.
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node* next;
};

struct node* adj[100];
int visited[100];

int queue[100], front = -1, rear = -1;

void enqueue(int x)
{
    if(front == -1)
        front = 0;

    rear++;
    queue[rear] = x;
}

int dequeue()
{
    int x = queue[front];
    front++;
    return x;
}

int isEmpty()
{
    if(front == -1 || front > rear)
        return 1;
    return 0;
}

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

void bfs(int s)
{
    enqueue(s);
    visited[s] = 1;

    while(!isEmpty())
    {
        int current = dequeue();
        printf("%d ", current);

        struct node* ptr = adj[current];

        while(ptr != NULL)
        {
            if(!visited[ptr->vertex])
            {
                enqueue(ptr->vertex);
                visited[ptr->vertex] = 1;
            }

            ptr = ptr->next;
        }
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

    printf("BFS Traversal: ");
    bfs(s);

    return 0;
}