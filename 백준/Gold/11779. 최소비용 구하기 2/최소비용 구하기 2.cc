#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

// Declare
#define INF 2e9

// Node
int N;

// Structure
struct Location {
    int cost, node;

    bool operator()(const Location& a, const Location& b) {
        return a.cost < b.cost;
    }
};

// Graph
vector<vector<Location>> edge;

void dijkstra(const int& start, int& end) {
    priority_queue<Location, vector<Location>, Location> que;
    vector<int> cost(N + 1, INF);
    vector<int> route(N + 1);

    que.push({ 0, start });
    cost[start] = 0;

    while (!que.empty()) {
        Location loc = que.top();
        que.pop();

        if (loc.cost > cost[loc.node])
            continue;

        for (Location outDegree : edge[loc.node]) {
            int c = outDegree.cost + loc.cost;
            int node = outDegree.node;

            if (cost[node] > c) {
                cost[node] = c;
                route[node] = loc.node;

                que.push({ c, node });
            }
        }
    }

    cout << cost[end] << "\n";

    stack<int> st;
    while (route[end] > 0) {
        st.push(end);
        end = route[end];
    }
    st.push(start);

    cout << st.size() << "\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> N >> M;

    edge.resize(N + 1);

    int u, v, cost;
    while (M--) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edge[u].push_back({ cost, v });
    }

    int start, end;
    cin >> start >> end;

    dijkstra(start, end);
}