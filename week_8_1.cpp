#include <iostream>
using namespace std;

#define INF 99999

int main() {
    int n;
    cin >> n;

    int graph[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int key[100], parent[100], visited[100];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
    }

    key[0] = 0;

    for (int count = 0; count < n - 1; count++) {
        int minKey = INF, u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && key[i] < minKey) {
                minKey = key[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;

    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
        totalCost += graph[i][parent[i]];
    }

    cout << "Minimum Cost = " << totalCost;

    return 0;
}