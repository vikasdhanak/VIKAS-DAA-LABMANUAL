#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    int graph[100][100];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int color[100];

    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }

    for (int start = 0; start < n; start++) {
        if (color[start] == -1) {
            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v = 0; v < n; v++) {
                    if (graph[u][v] == 1) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        }
                        else if (color[v] == color[u]) {
                            cout << "Not Bipartite";
                            return 0;
                        }
                    }
                }
            }
        }
    }

    cout << "Yes Bipartite";

    return 0;
}