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
    int node, dist;

    bool operator()(const Edge& a, const Edge& b) {
        return a.dist > b.dist;
    }
};

// Undirected Graph
vector<vector<Edge>> edge;

vector<int> dijkstra(int vertex) {
    priority_queue<Edge, vector<Edge>, Edge> que;
    vector<int> dist(edge.size(), INF);

    que.push({ vertex, 0 });
    dist[vertex] = 0;

    while (!que.empty()) {
        Edge e = que.top();
        que.pop();

        if (dist[e.node] < e.dist)
            continue;
        for (Edge _edge : edge[e.node]) {
            int distance = e.dist + _edge.dist;
            if (dist[_edge.node] < distance)
                continue;
            dist[_edge.node] = distance;
            que.push({ _edge.node, distance });
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, E;
    cin >> N >> E;

    edge.resize(N + 1);
    while (E--) {
        int u, v, c;
        cin >> u >> v >> c;

        // Undirected Graph
        edge[u].push_back({ v, c });
        edge[v].push_back({ u, c });
    }

    // Two Point
    int u, v;
    cin >> u >> v;

    vector<int> dist_o = dijkstra(1);
    vector<int> dist_u = dijkstra(u);
    vector<int> dist_v = dijkstra(v);

    // Validate & Print
    if ((dist_o[u] == INF || dist_u[v] == INF || dist_v[N])
        && (dist_o[v] == INF || dist_v[u] == INF || dist_u[N] == INF))
        cout << -1;
    else {
        // Shortest Distance
        int dist_ouv = dist_o[u] + dist_u[v] + dist_v[N];
        int dist_ovu = dist_o[v] + dist_v[u] + dist_u[N];
        cout << min(dist_ouv, dist_ovu);
    }
}