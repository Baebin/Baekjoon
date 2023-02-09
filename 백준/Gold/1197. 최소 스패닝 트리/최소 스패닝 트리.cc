#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Declare
#define INF 2e9

// Structure
struct Edge {
    int u, v, weight;

    bool operator<(const Edge& edge) {
        return weight < edge.weight;
    }
};

class Union {
public:
    Union(const int& N) { parent.assign(N + 1, -1); }
    int findRoot(const int& node) {
        if (parent[node] < 0)
            return node;
        return parent[node] = findRoot(parent[node]);
    }
    bool merge(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);

        // is Union
        if (x == y)
            return false;
        // Merge
        parent[y] = x;
        return true;
    }
protected:
    vector<int> parent;
};

class Kruskal : public Union {
public:
    Kruskal(const int& N) : Union(N) {}
    void push(Edge e) { this->edge.push_back(e); }
    int get() {
        sort(edge.begin(), edge.end());

        int cost = 0;
        for (Edge e : edge)
            if (Union::merge(e.u, e.v))
                cost += e.weight;
        return cost;
    }
private:
    vector<Edge> edge;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    Kruskal k(N);
    while (M--) {
        int u, v, weight;
        cin >> u >> v >> weight;
        k.push(Edge{ u, v, weight });
    }
    cout << k.get();
}