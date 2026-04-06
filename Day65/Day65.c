//Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.
#include <stdio.h>

int graph[100][100];
int visited[100];
int n, m;

int dfs(int node, int parent)
{
    visited[node] = 1;

    for(int i = 0; i < n; i++)
    {
        if(graph[node][i] == 1)
        {
            if(!visited[i])
            {
                if(dfs(i, node))
                    return 1;
            }
            else if(i != parent)
            {
                return 1;   // cycle found
            }
        }
    }

    return 0;
}

int main()
{
    int u, v;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            if(dfs(i, -1))
            {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");

    return 0;
}