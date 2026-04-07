//Problem: Detect cycle in directed graph using DFS and recursion stack.
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

bool visited[MAX];
bool recStack[MAX];
int graph[MAX][MAX];

bool dfs(int node, int V)
{
    visited[node] = true;
    recStack[node] = true;

    for(int i = 0; i < V; i++)
    {
        if(graph[node][i])
        {
            if(!visited[i] && dfs(i, V))
                return true;

            else if(recStack[i])
                return true;
        }
    }

    recStack[node] = false;
    return false;
}

// Function to check cycle in graph
bool hasCycle(int V)
{
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, V))
                return true;
        }
    }

    return false;
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            graph[i][j] = 0;

    for(int i = 0; i < E; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    if(hasCycle(V))
        printf("YES");
    else
        printf("NO");

    return 0;
}