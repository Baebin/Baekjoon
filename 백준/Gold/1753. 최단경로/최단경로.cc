#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Declear
#define INF 2e9

// Node
int V;

// Structure
typedef pair<int, int> Location;

void dijkstra(int& vertex, const vector<vector<Location>>& outDegree) {
    priority_queue<Location, vector<Location>, greater<Location>> que;
    vector<int> cost(V + 1, INF);

    que.push({ 0, vertex });
    cost[vertex] = 0;

    while (!que.empty()) {
        vertex = que.top().second;
        int pay = que.top().first;
        que.pop();

        if (cost[vertex] < pay)
            continue;

        for (auto loc : outDegree[vertex]) {
            int node = loc.first;
            int pay_next = pay + loc.second;

            if (cost[node] > pay_next) {
                cost[node] = pay_next;
                que.push({ pay_next, node });
            }
        }
    }

    for (int node = 1; node <= V; node++) {
        if (cost[node] == INF)
            cout << "INF\n";
        else cout << cost[node] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int E, N;
    cin >> V >> E >> N;
    vector<vector<Location>> outDegree(V + 1, vector<Location>());

    int u, w, v;
    while (E--) {
        cin >> u >> w >> v;
        outDegree[u].push_back({ w, v });
    }

    dijkstra(N, outDegree);
}