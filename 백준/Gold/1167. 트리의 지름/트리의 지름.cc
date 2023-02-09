#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Structure
struct Location {
    int node, distance;
};

// Graph
vector<bool> visit;
vector<vector<Location>> edge;

int dist = 0, node;
void DFS(int vertex, int distance) {
    visit[vertex] = true;

    if (distance > dist) {
        dist = distance;
        node = vertex;
    }
    for (Location loc : edge[vertex]) {
        if (visit[loc.node])
            continue;
        DFS(loc.node, distance + loc.distance);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V;
    cin >> V;

    visit.resize(V + 1);
    edge.resize(V + 1, vector<Location>());

    for (int i = 1; i <= V; i++) {
        int vertex;
        cin >> vertex;

        while (true) {
            int node, distance;
            cin >> node;
            if (node == -1)
                break;
            cin >> distance;

            edge[vertex].push_back({ node, distance });
        }
    }

    DFS(1, 0);
    visit.assign(V + 1, false);

    DFS(node, 0);
    cout << dist;
}