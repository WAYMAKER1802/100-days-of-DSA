//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100

int graph[MAX][MAX];
int dist[MAX];
bool visited[MAX];
int V;

int minDistance()
{
    int min = INT_MAX, min_index;

    for(int i = 0; i < V; i++)
    {
        if(!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

// Dijkstra Algorithm
void dijkstra(int src)
{
    for(int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for(int count = 0; count < V - 1; count++)
    {
        int u = minDistance();
        visited[u] = true;

        for(int v = 0; v < V; v++)
        {
            if(!visited[v] &&
               graph[u][v] &&
               dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

void printSolution(int src)
{
    printf("Shortest distances from source %d:\n", src);

    for(int i = 0; i < V; i++)
        printf("To %d -> %d\n", i, dist[i]);
}

int main()
{
    int E, src;

    printf("Enter number of vertices and edges:\n");
    scanf("%d %d", &V, &E);

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v weight):\n");
    for(int i = 0; i < E; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; 
    }

    printf("Enter source vertex:\n");
    scanf("%d", &src);

    dijkstra(src);
    printSolution(src);

    return 0;
}