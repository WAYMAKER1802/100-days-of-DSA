//Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.
#include <stdio.h>
#include <limits.h>

#define MAX 100

struct Edge
{
    int u, v, w;
};

int main()
{
    int V, E, src;

    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &V, &E);

    struct Edge edges[MAX];

    printf("Enter edges (u v weight):\n");
    for(int i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    printf("Enter source vertex:\n");
    scanf("%d", &src);

    int dist[MAX];
    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    for(int i = 1; i <= V - 1; i++)
    {
        for(int j = 0; j < E; j++)
        {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for(int j = 0; j < E; j++)
    {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            printf("Graph contains negative weight cycle\n");
            return 0;
        }
    }

    printf("Shortest distances from source %d:\n", src);

    for(int i = 0; i < V; i++)
        printf("To %d -> %d\n", i, dist[i]);

    return 0;
}