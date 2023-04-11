#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Declare
#define INF 2e9

// Struct
struct Edge {
    int S, D, C;

    bool operator<(const Edge &edge) {
        return (C < edge.C);
    }
};

class Union {
public:
    Union(const int &N) {
        parent.resize(N);
        for (int i = 1; i < N; i++)
            parent[i] = i;
    }
    int findParent(const int &NODE) {
        if (parent[NODE] == NODE)
            return NODE;
        return (parent[NODE] = findParent(parent[NODE]));
    }
    bool merge(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if (x == y)
            return false;
        parent[y] = x;
        return true;
    }
protected:
    vector<int> parent;
};

class Kruskal : Union {
public:
    Kruskal(const int &N) : Union(N) {}
    void insert(const Edge &edge) {
        edges.emplace_back(edge);
    }
    int get() {
        sort(edges.begin(), edges.end());

        int cost = 0;
        for (Edge edge : edges) {
            if (!Union::merge(edge.S, edge.D))
                continue;
            cost += edge.C;
        }
        return cost;
    }
private:
    vector<Edge> edges;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, P;
    cin >> N >> P;

    int min_cost = INF;
    vector<int> costs(N + 1);
    for (register int i = 1; i <= N; i++) {
        cin >> costs[i];
        min_cost = min(min_cost, costs[i]);
    }

    Kruskal kruskal(N + 1);
    while (P--) {
        int S, D, C;
        cin >> S >> D >> C;

        // 왕복 2번 + 출발 지점 돌아오기 + 다음 지점 도착
        kruskal.insert(Edge{ S, D, 2 * C + costs[S] + costs[D] });
    }
    // 간선 비용이 짧은 쪽이 시작 지점
    cout << (kruskal.get() + min_cost);
}