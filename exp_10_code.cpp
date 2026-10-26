
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V, E;

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    const long long INF = LLONG_MAX / 4;
    vector<long long> dist(V, INF);

    // Step 1: Distance to source is zero
    dist[src] = 0;

    // Step 2: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != INF &&
                dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Step 3: Detect negative-weight cycle
    bool negativeCycle = false;

    for (int j = 0; j < E; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != INF &&
            dist[u] + wt < dist[v]) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Negative-weight cycle detected!\n";
    } else {
        cout << "\nShortest distances from source " << src << ":\n";

        for (int i = 0; i < V; i++) {
            if (dist[i] == INF) {
                cout << "Vertex " << i << " : Unreachable\n";
            } else {
                cout << "Vertex " << i << " : " << dist[i] << "\n";
            }
        }
    }

    return 0;
}
