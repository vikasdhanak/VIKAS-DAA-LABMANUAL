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

    int dist[100], visited[100], parent[100];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minDist = INF, u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) {
            break;
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v]) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << " : ";

        if (dist[i] == INF) {
            cout << "No Path";
        } else {
            cout << "Distance = " << dist[i] << ", Path = ";
            printPath(parent, i);
        }

        cout << endl;
    }

    return 0;
}