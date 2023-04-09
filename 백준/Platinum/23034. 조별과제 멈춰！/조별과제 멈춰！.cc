#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Declare
#define INF 2e9
#define endl "\n"

struct Edge {
    int S, D, cost;

    bool operator<(const Edge &e) {
        return cost < e.cost;
    }
};

struct Node {
    int node, cost;
};

class Union {
public:
    explicit Union(const int &N) {
        this->N = N;
        this->parent.resize(N + 1);

        for (int i = 1; i <= N; i++)
            parent[i] = i;
    }
    int findParent(const int &node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    bool merge(const int &x, const int &y) {
        int root_x = findParent(x);
        int root_y = findParent(y);

        if (root_x == root_y)
            return false;
        parent[root_y] = root_x;
        return true;
    }
protected:
    int N;
    vector<int> parent;
};

class Kruskal : Union {
public:
    explicit Kruskal(const int &N) : Union(N) {
        route.resize(N + 1);
    }
    int get() {
        int cost = 0;

        sort(edge.begin(), edge.end());
        for (Edge e: edge) {
            if (!Union::merge(e.S, e.D))
                continue;
            route[e.S].push_back(Node{ e.D, e.cost });
            route[e.D].push_back(Node{ e.S, e.cost });
            cost += e.cost;
        }
        return cost;
    }
    void insert(const Edge &e) {
        edge.push_back(e);
    }
    const vector<vector<Node>> &getRoute() const {
        return route;
    }
private:
    vector<Edge> edge;
    vector<vector<Node>> route;
};

class BFS {
public:
    BFS(const int &N, const vector<vector<Node>> &edge) {
        this-> N = N;
        this->cost.resize(N + 1, vector<int>(N + 1));
        this->edge = edge;
    }
    void run(const int &start) {
        que.push(Node{ start, 0 });

        vector<bool> visit(N + 1);
        visit[start] = true;

        while (!que.empty()) {
            Node cur = que.front();
            que.pop();

            for (Node next : edge[cur.node]) {
                // Visit Check
                if (visit[next.node])
                    continue;
                visit[next.node] = true;

                // Max Cost?
                int c = cur.cost;
                if (c < next.cost)
                    c = next.cost;
                cost[start][next.node] = c;
                que.push(Node{ next.node, c });
            }
        }
    }
    int getMaxCost(const int &S, const int &D) {
        return (cost[S][D] == INF ? 0 : cost[S][D]);
    }
private:
    int N;
    queue<Node> que;
    vector<vector<int>> cost;
    vector<vector<Node>> edge;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    Kruskal k(N);
    vector<vector<Node>> edge(N + 1);

    int A, B, C;
    while (M--) {
        cin >> A >> B >> C;
        k.insert(Edge{ A, B, C });
        edge[A].push_back(Node{ B, C });
        edge[B].push_back(Node{ A, C });
    }
    int cost = k.get();

    BFS bfs(N, k.getRoute());
    for (int vertex = 1; vertex <= N; vertex++)
        bfs.run(vertex);

    int T;
    cin >> T;

    while (T--) {
        cin >> A >> B;
        cout << cost - bfs.getMaxCost(A, B) << endl;
    }
}