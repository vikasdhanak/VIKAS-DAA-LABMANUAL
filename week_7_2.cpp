#include <iostream>
using namespace std;

#define INF 99999

void printPath(int parent[], int v) {
    if (parent[v] == -1) {
        cout << v;
        return;
    }

    printPath(parent, parent[v]);
    cout << " -> " << v;
}

int main() {
    int n;
    cin >> n;

    int graph[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int source;
    cin >> source;

    int dist[100], parent[100];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int k = 0; k < n - 1; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (graph[u][v] != 0 && dist[u] != INF) {
                    if (dist[u] + graph[u][v] < dist[v]) {
                        dist[v] = dist[u] + graph[u][v];
                        parent[v] = u;
                    }
                }
            }
        }
    }

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && dist[u] != INF) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    cout << "Negative Weight Cycle Exists";
                    return 0;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " : ";

        if (dist[i] == INF) {
            cout << "No Path";
        } else {
            cout << "Path = ";
            printPath(parent, i);
            cout << ", Weight = " << dist[i];
        }

        cout << endl;
    }

    return 0;
}