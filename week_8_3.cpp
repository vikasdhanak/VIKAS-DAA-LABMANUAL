#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w > b.w;
}

int findParent(int parent[], int x) {
    if (parent[x] == x) {
        return x;
    }
    return findParent(parent, parent[x]);
}

void unionSet(int parent[], int a, int b) {
    int pa = findParent(parent, a);
    int pb = findParent(parent, b);
    parent[pa] = pb;
}

int main() {
    int n;
    cin >> n;

    int graph[100][100];
    Edge edges[10000];

    int edgeCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];

            if (graph[i][j] != 0 && i < j) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].w = graph[i][j];
                edgeCount++;
            }
        }
    }

    sort(edges, edges + edgeCount, compare);

    int parent[100];

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int maxBudget = 0;
    int roads = 0;

    for (int i = 0; i < edgeCount && roads < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (findParent(parent, u) != findParent(parent, v)) {
            unionSet(parent, u, v);
            maxBudget += w;
            roads++;
        }
    }

    cout << "Maximum Spanning Weight = " << maxBudget;

    return 0;
}