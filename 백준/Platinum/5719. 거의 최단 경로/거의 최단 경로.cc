#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Decalre
#define INF 2e9

// Structure
struct Location {
    int node, distance;

    // Reverse
    bool operator()(Location& a, Location& b) {
        return a.distance > b.distance;
    }
};

vector<int> dijkstra(int node, const vector<vector<Location>>& edge, const vector<vector<bool>>& visit, vector<vector<int>>& route) {
    int N = edge.size();

    priority_queue<Location, vector<Location>, Location> que;
    que.push({ node, 0 });

    vector<int> dist(N, INF);
    dist[node] = 0;

    while (!que.empty()) {
        Location loc = que.top();
        que.pop();

        if (dist[loc.node] < loc.distance)
            continue;

        for (Location data : edge[loc.node]) {
            // Validate
            if (visit[loc.node][data.node])
                continue;

            int dis = data.distance + loc.distance;
            if (dist[data.node] < dis)
                continue;

            if (dist[data.node] > dis) {
                route[data.node].clear();
                dist[data.node] = dis;
                que.push({ data.node, dis });
            }
            // Tracking
            route[data.node].push_back(loc.node);
        }
    }

    return dist;
}

// BFS
void delete_route(const int& destination, const vector<vector<int>>& route, vector<vector<bool>>& v) {
    queue<int> que;
    que.push(destination);

    int N = v.size();
    vector<bool> visit(N);
    visit[destination] = true;

    while (!que.empty()) {
        int vertex = que.front();
        que.pop();

        for (int node : route[vertex]) {
            v[node][vertex] = true;

            // Visit Check
            if (visit[node])
                continue;
            visit[node] = true;
            que.push(node);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        int N, M;
        cin >> N >> M;

        // End
        if (N == 0 && M == 0)
            break;

        int S, D;
        cin >> S >> D;

        vector<vector<int>> route(N, vector<int>());
        vector<vector<Location>> edge(N, vector<Location>());
        while (M--) {
            int U, V, P;
            cin >> U >> V >> P;
            edge[U].push_back({ V, P });
        }

        vector<vector<bool>> visit(N, vector<bool>(N));
        vector<int> dist = dijkstra(S, edge, visit, route);
        if (dist[D] == INF) {
            cout << -1 << "\n";
            continue;
        }

        delete_route(D, route, visit);
        dist = dijkstra(S, edge, visit, route);
        cout << (dist[D] != INF ? dist[D] : -1) << "\n";
    }
}