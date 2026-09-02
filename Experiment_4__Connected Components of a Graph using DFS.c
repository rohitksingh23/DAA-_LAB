// Name: Rohit  Kumar singh
// Roll Number: 25/DA/055

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];   
bool visited[MAX];
int n;               

void dfs(int v) {
    visited[v] = true;
    printf("%d ", v);

    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int edges;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    for (int i = 0; i < n; i++)
        visited[i] = false;

    printf("Connected Components:\n");
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            printf("\n");
        }
    }

    return 0;
}
