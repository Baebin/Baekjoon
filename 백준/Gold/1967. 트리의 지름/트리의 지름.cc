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

    int N;
    cin >> N;

    visit.resize(N + 1);
    edge.resize(N + 1, vector<Location>());

    for (int i = 1; i < N; i++) {
        int vertex, node, distance;
        cin >> vertex >> node >> distance;

        edge[vertex].push_back({ node, distance });
        edge[node].push_back({ vertex, distance });
    }

    DFS(1, 0);
    visit.assign(N + 1, false);

    DFS(node, 0);
    cout << dist;
}