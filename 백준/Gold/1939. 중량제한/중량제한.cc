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
    bool isMerged(const int &X, const int &Y) {
        int px = find_parent(X);
        int py = find_parent(Y);
        return (px == py);
    }
private:
    vector<int> parent;
};

class Kruskal : Union {
public:
    Kruskal(const vector<Edge> &edges, const int &N, const int &A, const int &B) : edges(edges), Union(N + 1), A(A), B(B) {
        sort(this->edges.begin(), this->edges.end(), cmp);
    }
    int get() {
        int cost = 1;
        for (Edge edge: edges) {
            if (!Union::merge(edge.start, edge.destination))
                continue;
            if (!isMerged(A, B))
                continue;
            return edge.cost;
        }
        return cost;
    }
protected:
    static bool cmp(const Edge &A, const Edge &B) {
        return (A.cost > B.cost);
    }
private:
    int A, B;
    vector<Edge> edges;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        int X, Y, C;
        cin >> X >> Y >> C;
        edges[i] = Edge{ C, X, Y };
    }

    int A, B;
    cin >> A >> B;
    Kruskal kruskal(edges, N, A, B);

    cout << kruskal.get();
}