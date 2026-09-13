// Rohit kumar Singh
// 25/DA/055

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int tin[MAX];
int low[MAX];
int articulation[MAX];

int timer = 0;
int n;

/*
    DFS function
    u      = current vertex
    parent = parent of u in DFS tree
*/
void dfs(int u, int parent)
{
    visited[u] = 1;

    // Discovery time of u
    tin[u] = low[u] = timer++;

    int children = 0;

    for (int v = 0; v < n; v++)
    {
        // No edge between u and v
        if (graph[u][v] == 0)
            continue;

        // Ignore the edge going back to parent
        if (v == parent)
            continue;

        // If v is not visited
        if (!visited[v])
        {
            children++;

            // DFS on child
            dfs(v, u);

            // Update low value of u
            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            /*
                If u is not root and
                subtree of v cannot reach
                an ancestor of u
            */
            if (parent != -1 && low[v] >= tin[u])
            {
                articulation[u] = 1;
            }
        }

        // Back edge
        else
        {
            low[u] = (low[u] < tin[v]) ? low[u] : tin[v];
        }
    }

    /*
        Special condition for DFS root:
        Root is an articulation point
        if it has more than one child.
    */
    if (parent == -1 && children > 1)
    {
        articulation[u] = 1;
    }
}

int main()
{
    int edges;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges:\n");

    for (int i = 0; i < edges; i++)
    {
        int u, v;

        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;   // Undirected graph
    }

    // Initialize arrays
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        tin[i] = -1;
        low[i] = -1;
        articulation[i] = 0;
    }

    // Handle disconnected graph
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1);
        }
    }

    printf("\nArticulation Points are: ");

    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (articulation[i])
        {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
    {
        printf("None");
    }

    printf("\n");

    return 0;
}