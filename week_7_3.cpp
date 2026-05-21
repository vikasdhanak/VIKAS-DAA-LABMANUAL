#include <iostream>
using namespace std;

#define INF 99999

int main() {
    int V;
    cin >> V;

    int graph[100][100];

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int source, destination, k;
    cin >> source >> destination;
    cin >> k;

    int dp[100][100][100];

    for (int e = 0; e <= k; e++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dp[e][i][j] = INF;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        dp[0][i][i] = 0;
    }

    for (int e = 1; e <= k; e++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                for (int a = 0; a < V; a++) {
                    if (graph[i][a] != 0 && dp[e - 1][a][j] != INF) {
                        int cost = graph[i][a] + dp[e - 1][a][j];

                        if (cost < dp[e][i][j]) {
                            dp[e][i][j] = cost;
                        }
                    }
                }
            }
        }
    }

    if (dp[k][source][destination] == INF) {
        cout << "no path of length k is available";
    } else {
        cout << dp[k][source][destination];
    }

    return 0;
}