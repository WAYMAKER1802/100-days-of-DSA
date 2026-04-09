//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int indegree[MAX];
int queue[MAX];

int main()
{
    int V, E;
    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &V, &E);

    // Initialize graph and indegree
    for(int i = 0; i < V; i++)
    {
        indegree[i] = 0;
        for(int j = 0; j < V; j++)
            graph[i][j] = 0;
    }

    // Input edges
    printf("Enter directed edges (u v):\n");
    for(int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        indegree[v]++;
    }

    // Insert nodes with indegree 0 into queue
    int front = 0, rear = 0;

    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }

    printf("Topological Order:\n");

    while(front < rear)
    {
        int node = queue[front++];
        printf("%d ", node);

        // Reduce indegree of adjacent nodes
        for(int i = 0; i < V; i++)
        {
            if(graph[node][i])
            {
                indegree[i]--;

                if(indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    return 0;
}