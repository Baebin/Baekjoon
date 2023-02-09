#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define INF 2e9

// Structure
struct Location {
    int vertex, node, distance;
};

bool bellmanFord(const int& N, const vector<Location>& edge) {
    vector<int> dist(N + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= N; i++) {
        bool cycle = true;

        for (Location loc : edge) {
            int distance = dist[loc.vertex] + loc.distance;
            if (distance < dist[loc.node]) {
                if (i == N) return true;

                dist[loc.node] = distance;
                cycle = false;
            }
        }

        if (cycle)
            break;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;

    while (TC--) {
        int N, M, W;
        cin >> N >> M >> W;

        vector<Location> edge;

        int S, E, T;
        for (int i = 1; i <= M; i++) {
            // Road
            cin >> S >> E >> T;
            edge.push_back({ S, E, T });
            edge.push_back({ E, S, T });
        }

        for (int i = 1; i <= W; i++) {
            // Wormhole
            cin >> S >> E >> T;
            edge.push_back({ S, E, -T });
        }

        cout << (bellmanFord(N, edge) ? "YES" : "NO") << "\n";
    }
}