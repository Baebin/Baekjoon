#include <iostream>
#include <vector>
using namespace std;

// Declear
#define INF 2e9

// Node
int N;

// Structure
struct Location {
    int from, to, time;
};

pair<bool, vector<long long>> ballmanFord(int vertex, vector<Location>& edge) {
    vector<long long> cost(N + 1, INF);
    cost[vertex] = 0;

    for (int i = 1; i <= N; i ++) {
        bool cycle = true;

        for (Location loc : edge) {
            if (cost[loc.from] == INF)
                continue;

            long long cost_next = cost[loc.from] + loc.time;
            if (cost[loc.to] > cost_next) {
                if (i == N) return { true, cost };
                cost[loc.to] = cost_next;
                cycle = false;
            }
        }

        if (cycle)
            break;
    }

    return { false, cost };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> N >> M;
    vector<Location> edge(M);

    int from, to, time;
    while (M--) {
        cin >> from >> to >> time;
        edge[M] = { from, to, time };
    }
    auto data = ballmanFord(1, edge);

    // Cycle
    if (data.first) {
        cout << -1;
        return 0;
    }
    
    // Start Exception
    for (int i = 2; i <= N; i++) {
        if (data.second[i] == INF)
            cout << -1 << "\n";
        else cout << data.second[i] << "\n";
    }
}