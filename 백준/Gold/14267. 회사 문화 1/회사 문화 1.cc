#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define INF 2e9

// Preorder
vector<int> idx_root;
vector<int> idx_leaf;
vector<vector<int>> edge;

class LazySegmentTree {
public:
    LazySegmentTree(const int& N) {
        this->container = vector<int>(N);
        tree.resize(N * 4);
        lazy.resize(N * 4);
    }
    void update(const int& start, const int& end, const int& node, const int& left, const int& right, const int& value) {
        update_lazy(start, end, node);
        if (right < start || left > end)
            return;
        if (left <= start && end <= right) {
            tree[node] += value;
            if (start != end) {
                lazy[node * 2] += value;
                lazy[node * 2 + 1] += value;
            }
            return;
        }
        int mid = (start + end) / 2;
        update(start, mid, node * 2, left, right, value);
        update(mid + 1, end, node * 2 + 1, left, right, value);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    int sum(const int& start, const int& end, const int& node, const int& left, const int& right) {
        update_lazy(start, end, node);
        if (right < start || left > end)
            return 0;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
    }
protected:
    void update_lazy(const int& start, const int& end, const int& node) {
        if (lazy[node] == 0)
            return;
        tree[node] += lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
private:
    vector<int> container;
    vector<int> tree;
    vector<int> lazy;
};

// Euler Tour Technique
int idx = 0;
void DFS(const int& vertex) {
    idx_root[vertex] = ++idx;
    for (int node : edge[vertex])
        DFS(node);
    idx_leaf[vertex] = idx;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    // Resize
    idx_root.resize(N + 1);
    idx_leaf.resize(N + 1);

    // Tree
    LazySegmentTree tree(N);

    int idx;
    edge.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> idx;
        if (idx != -1)
            edge[idx].push_back(i);
    }
    // Root Node: 1
    DFS(1);

    int I, W;
    while (M--) {
        cin >> I >> W;
        tree.update(0, N - 1, 1, idx_root[I] - 1, idx_leaf[I] - 1, W);
    }
    for (int i = 1; i <= N; i++)
        cout << tree.sum(0, N - 1, 1, idx_root[i] - 1, idx_root[i] - 1) << " ";
}