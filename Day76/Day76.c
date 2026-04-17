//Problem Statement : Using DFS or BFS, count number of connected components.
#include <stdio.h>

int adj[100][100];
int visited[100];
int n, m;

void dfs(int node)
{
    visited[node] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[node][i] == 1 && !visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    int u, v;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }
    for(int i = 0; i < n; i++)
        visited[i] = 0;

    int components = 0;

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);

    return 0;
}
