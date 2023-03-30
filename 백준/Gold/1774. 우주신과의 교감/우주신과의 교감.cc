#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroint-loops")

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
// Struct
typedef long long ll;

struct Location {
    int x, y;
};

struct Edge {
    double cost;
    int start, destination;
};
class Union {
public:
    Union(const int &N) {
        parent.resize(N);
        for (int i = 1; i < N; i++)
            parent[i] = i;
    }
    int find_parent(const int &node) {
        if (parent[node] == node)
            return node;
        return (parent[node] = find_parent(parent[node]));
    }
    bool merge(const int &X, const int &Y) {
        int px = find_parent(X);
        int py = find_parent(Y);
        if (px == py)
            return false;
        parent[py] = px;
        return true;
    }
private:
    vector<int> parent;
};
class Kruskal : Union {
public:
    Kruskal(const vector<Location> &locs) : Union(locs.size()) {
        const int SIZE = locs.size();
        for (int i = 0; i < SIZE - 1; i++)
            for (int j = i + 1; j < SIZE; j++)
                edges.push_back(Edge{ getDistance(locs[i], locs[j]), i, j });
        sort(edges.begin(), edges.end(), cmp);
    }
    double get() {
        double cost = 0;
        for (Edge edge: edges) {
            if (!Union::merge(edge.start, edge.destination))
                continue;
            cost += edge.cost;
        }
        return cost;
    }
    void merge(const int &X, const int &Y) {
        Union::merge(X, Y);
    }
protected:
    double getDistance(const Location &A, const Location &B) {
        const ll X = (A.x - B.x);
        const ll Y = (A.y - B.y);
        return sqrt((X * X) + (Y * Y));
    }
    static bool cmp(const Edge &A, const Edge &B) {
        return (A.cost < B.cost);
    }
private:
    vector<Edge> edges;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Location> vec(N);
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        vec[i] = Location{ X, Y };
    }

    Kruskal kruskal(vec);
    while (M--) {
        int A, B;
        cin >> A >> B;
        kruskal.merge(A - 1, B - 1);
    }

    cout << fixed;
    cout.precision(2);

    cout << kruskal.get();
}