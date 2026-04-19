//Problem Statement : Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.
#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int key[MAX];

int minKey(int n)
{
    int min = INT_MAX, index;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i] && key[i] < min)
        {
            min = key[i];
            index = i;
        }
    }

    return index;
}

int primMST(int n)
{
    for(int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0; // start from vertex 0

    int totalWeight = 0;

    for(int count = 0; count < n; count++)
    {
        int u = minKey(n);
        visited[u] = 1;

        totalWeight += key[u];

        for(int v = 0; v < n; v++)
        {
            if(graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            graph[i][j] = 0;

    int u, v, w;

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // undirected graph
    }

    printf("%d\n", primMST(n));

    return 0;
}