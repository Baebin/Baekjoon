#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroint-loops")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int cost;
    int start, destination;

    bool operator<(const Edge &edge) {
        return cost < edge.cost;
    }
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
    Kruskal(const vector<Edge> &edges, const int &N) : Union(N + 1), N(N), edges(edges) {
        sort(this->edges.begin(), this->edges.end());
    }
    int get() {
        int cost = 0, cnt = 0;
        for (Edge edge: edges) {
            if (!Union::merge(edge.start, edge.destination))
                continue;
            cnt++;
            cost += edge.cost;
        }
        if (cnt + 1 != N)
            return -1;
        return cost;
    }
private:
    int N;
    vector<Edge> edges;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    vector<char> school(N);

    for (int i = 0; i < N; i++)
        cin >> school[i];

    for (int i = 0; i < M; i++) {
        int U, V, D;
        cin >> U >> V >> D;

        if (school[U - 1] != school[V - 1])
            edges.push_back(Edge{ D, U, V });
    }
    Kruskal kruskal(edges, N);

    cout << kruskal.get();
}