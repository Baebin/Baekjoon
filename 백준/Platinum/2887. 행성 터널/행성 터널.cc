#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure
struct Location {
    int pos, cost;

    bool operator<(Location& a) {
        return cost < a.cost;
    }
};

struct Edge {
    int u, v, cost;

    bool operator<(Edge& a) {
        return cost < a.cost;
    }
};

class Union {
public:
    Union(const int& N) {
        parent.resize(N);
        for (int i = 0; i < N; i++)
            parent[i] = i;
    }
    int findParent(const int& node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    bool merge(const int& x, const int& y) {
        int root_x = findParent(x);
        int root_y = findParent(y);

        // is Union
        if (root_x == root_y)
            return false;
        // Merge
        parent[root_y] = root_x;
        return true;
    }
private:
    vector<int> parent;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<Location> X(N);
    vector<Location> Y(N);
    vector<Location> Z(N);

    int x, y, z;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> z;

        X[i] = { i, x };
        Y[i] = { i, y };
        Z[i] = { i, z };
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    vector<Edge> edge;
    for (int i = 1; i < N; i++) {
        edge.push_back({ X[i - 1].pos, X[i].pos, abs(X[i].cost - X[i - 1].cost) });
        edge.push_back({ Y[i - 1].pos, Y[i].pos, abs(Y[i].cost - Y[i - 1].cost) });
        edge.push_back({ Z[i - 1].pos, Z[i].pos, abs(Z[i].cost - Z[i - 1].cost) });
    }
    sort(edge.begin(), edge.end());

    Union u(N); int cost = 0;
    for (Edge e : edge)
        if (u.merge(e.u, e.v))
            cost += e.cost;
    cout << cost;
}