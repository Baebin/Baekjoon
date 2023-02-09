#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Declare
#define INF 2e9

// Structure
struct Edge {
    int node, cost;

    bool operator()(const Edge& a, const Edge& b) {
        return a.cost > b.cost;
    }
};

// Directed Graph
vector<vector<Edge>> edge;

int dijkstra(int vertex, const int& destination) {
    priority_queue<Edge, vector<Edge>, Edge> que;
    vector<int> cost(edge.size(), INF);

    que.push({ vertex, 0 });
    cost[vertex] = 0;

    while (!que.empty()) {
        Edge e = que.top();
        que.pop();

        if (cost[e.node] < e.cost)
            continue;
        for (Edge _edge : edge[e.node]) {
            int time = e.cost + _edge.cost;
            if (cost[_edge.node] < time)
                continue;
            cost[_edge.node] = time;
            que.push({ _edge.node, time });
        }
    }
    return cost[destination];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, X;
    cin >> N >> M >> X;

    edge.resize(N + 1);
    while (M--) {
        int u, v, c;
        cin >> u >> v >> c;

        // Directed Graph
        edge[u].push_back({ v, c });
    }

    int time = 0;
    for (int i = 1; i <= N; i++)
        time = max(time, dijkstra(X, i) + dijkstra(i, X));
    cout << time;
}