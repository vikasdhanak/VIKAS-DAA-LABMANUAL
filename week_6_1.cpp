#include <iostream>
using namespace std;

void dfs(int v, int n, int graph[][100], bool visited[]) {
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i, n, graph, visited);
        }
    }
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

    int source, destination;
    cin >> source >> destination;

    bool visited[100] = {false};

    dfs(source, n, graph, visited);

    if (visited[destination]) {
        cout << "Path Exists";
    } else {
        cout << "Path Does Not Exist";
    }

    return 0;
}