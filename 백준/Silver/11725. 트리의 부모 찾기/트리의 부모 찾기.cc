#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Node
int N;

// Graph
vector<int> parent;
vector<vector<int>> graph;

void BFS() {
    queue<int> que;
    que.push(1);

    parent[1] = true;
    while (!que.empty()) {
        int vertex = que.front();
        que.pop();

        for (int node : graph[vertex]) {
            if (parent[node])
                continue;
            parent[node] = vertex;
            que.push(node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    parent.resize(N + 1);
    graph.resize(N + 1);

    int u, v;
    for (int i = 1; i < N; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    BFS();
    for (int i = 2; i <= N; i++)
        cout << parent[i] << "\n";
}