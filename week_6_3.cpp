#include <iostream>
using namespace std;

bool dfs(int u, int n, int graph[][100], int visited[]) {
    visited[u] = 1;

    for (int v = 0; v < n; v++) {
        if (graph[u][v] == 1) {
            if (visited[v] == 1) {
                return true;
            }
            if (visited[v] == 0) {
                if (dfs(v, n, graph, visited)) {
                    return true;
                }
            }
        }
    }

    visited[u] = 2;
    return false;
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

    int visited[100] = {0};

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (dfs(i, n, graph, visited)) {
                cout << "Yes Cycle Exists";
                return 0;
            }
        }
    }

    cout << "No Cycle Exists";

    return 0;
}