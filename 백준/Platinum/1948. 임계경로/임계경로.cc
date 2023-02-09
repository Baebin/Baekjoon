#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure
typedef long long ll;

struct Edge {
    int node, time;
};

// Topological Sort
vector<int> inDegree;
vector<vector<Edge>> edge;

// DFS Validate
int depth_max = 0;
vector<bool> visit;
vector<vector<Edge>> edge_reverse;

void DFS(const int& vertex, const vector<int>& cost) {
    if (visit[vertex])
        return;
    visit[vertex] = true;

    for (Edge e : edge_reverse[vertex]) {
        if (cost[e.node] == cost[vertex] - e.time) {
            DFS(e.node, cost);
            depth_max++;
        }
    }
}

vector<int> topologicalSort(const int& N) {
    vector<int> cost(N + 1);
    queue<int> que;

    int cost_max = 0;
    for (int i = 1; i <= N; i++)
        if (inDegree[i] == 0)
            que.push(i);
    while (!que.empty()) {
        int vertex = que.front();
        que.pop();

        for (Edge e : edge[vertex]) {
            int time = cost[vertex] + e.time;
            if (cost[e.node] < time)
                cost[e.node] = time;
            if (--inDegree[e.node] == 0)
                que.push(e.node);
        }
    }
    return cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // Graph
    edge.resize(N + 1);
    inDegree.resize(N + 1);

    // DFS Tracking 
    visit.resize(N + 1);
    edge_reverse.resize(N + 1);

    while (M--) {
        int u, v, time;
        cin >> u >> v >> time;

        inDegree[v]++;
        edge[u].push_back({ v, time });
        edge_reverse[v].push_back({ u, time });
    }
    int start, destination;
    cin >> start >> destination;

    // Find the Longest Path
    vector<int> cost = topologicalSort(N);
    DFS(destination, cost);

    int time_max = 0;
    for (int time : cost)
        time_max = max(time_max, time);
    cout << time_max << "\n" << depth_max;
}