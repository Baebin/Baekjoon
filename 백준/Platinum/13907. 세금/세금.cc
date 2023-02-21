#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Declare
#define INF 2e9
#define endl "\n"

// Number of (Cities & Roads & Increases)
// (Start Vertex and Destination)
int N, M, K;
int S, D;

// Structure(Max Heap)
struct Edge {
    int node, dis, cnt;
    bool operator()(const Edge& a, const Edge& b) { return (a.dis > b.dis); }
};

// Cost(S->D): [Destination][Number of Edges] = Min Cost
// Edge(V->V): [Vertex] = { Edge_A, Edge_A, Edge_A, ... }
vector<vector<int>> cost;
vector<vector<Edge>> edge;

void dijkstra() {
    priority_queue<Edge, vector<Edge>, Edge> que;
    que.push(Edge{ S, 0, 0 });
    cost[S][0] = 0;

    while (!que.empty()) {
        Edge cur = que.top();
        que.pop();

        if (cost[cur.node][cur.cnt] < cur.dis || cur.cnt == N)
            continue;
        for (const Edge &next : edge[cur.node]) {
            int dis = cur.dis + next.dis;
            int cnt = cur.cnt + 1;
            if (!(dis < cost[next.node][cnt]))
                continue;
            cost[next.node][cnt] = dis;
            que.push(Edge{ next.node, dis, cnt });
        }
    }
}

int getTax(const int& weight) {
    int min_cost = INF;
    for (int cnt = 1; cnt <= N; cnt++)
        min_cost = min(min_cost, cost[D][cnt] + (cnt * weight));
    return min_cost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K >> S >> D;
    edge.resize(N + 1, vector<Edge>());
    cost.resize(N + 1, vector<int>(N + 1, INF));

    while (M--) {
        // Road Information
        int A, B, W;
        cin >> A >> B >> W;

        edge[A].push_back(Edge{ B, W });
        edge[B].push_back(Edge{ A, W });
    }
    dijkstra();

    int weight = 0;
    cout << getTax(0) << endl;
    while (K--) {
        int P;
        cin >> P;
        cout << getTax(weight += P) << endl;
    }
}