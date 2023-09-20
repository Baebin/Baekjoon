#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2e9
// (0 ~ N-1)
#define fori(x,y) for (register int i = (x); i < (y); i++)

// Directed Edge
struct Arc {
    int node, cost;
};

// Undirected Edge
struct Edge {
    // NodeA, NodeB
    int na, nb, cost;
    bool operator()(const Edge& e1,const Edge& e2) {
        return (e1.cost > e2.cost);
    }
};

class Union {
public:
    Union(const int& N) : N{ N } {
        parent.resize(N + 1);
        fori(1, N + 1) parent[i] = i;
    }
    int find(const int& node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    bool merge(const int& x, const int& y) {
        int px = find(x);
        int py = find (y);

        // is Union?
        if (px == py) return false;

        // isn't Union
        parent[py] = px;
        return true;
    }
protected:
    int N;
    vector<int> parent;
};

class Kruskal : Union {
public:
    Kruskal(const int& N,
            const vector<int> buildings,
            const vector<bool> canVisit,
            const vector<vector<Arc>>& edges)
        : Union(N), buildings{ buildings }, canVisit{ canVisit }, edges{ edges } {
    }
    int run() {
        priority_queue<Edge, vector<Edge>, Edge> que, buildingQue;
        /*
        Route Separation
        - que: Safe <-> Safe
        - buildingQue: Safe <-> Unsafe
        */
        fori(1, N + 1)
        for (const Arc &arc: edges[i])
            // Exception (N == 2)
            if (N == 2 || (canVisit[i] && canVisit[arc.node]))
                que.push(Edge{i, arc.node, arc.cost});
            else if (canVisit[i] ^ canVisit[arc.node])
                buildingQue.push(Edge{i, arc.node, arc.cost});
        // Safe Route
        int cost = 0, unions = N - 1;
        while (!que.empty()) {
            const Edge& edge = que.top();
            if (Union::merge(edge.na, edge.nb))
                (cost += edge.cost), unions--;
            que.pop();
        }
        // Exception
        if (N == 1)
            return 0;
        if (N == 2)
            if (unions) return INF;
            else return cost;

        // Last Unions
        if (unions != buildings.size())
            return INF;
        // Safe <-> Unsafe Route
        while (!buildingQue.empty()) {
            const Edge& edge = buildingQue.top();
            if (Union::merge(edge.na, edge.nb))
                (cost += edge.cost), unions--;
            buildingQue.pop();
        }
        // All Completed?
        return (unions ? INF : cost);
    }
private:
    vector<int> buildings;
    vector<bool> canVisit;
    vector<vector<Arc>> edges;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, P;
    cin >> N >> M >> P;

    vector<int> buildings(P);
    vector<bool> canVisit(N + 1, true);
    while (P--) (cin >> buildings[P]), canVisit[buildings[P]] = false;

    vector<vector<Arc>> edges(N + 1);
    while (M--) {
        int x, y, c;
        cin >> x >> y >> c;
        edges[x].emplace_back(Arc{ y, c });
    }

    // Output
    int ans = Kruskal(N, buildings, canVisit, edges).run();
    if (ans != INF) cout << ans;
    else cout << "impossible";
}