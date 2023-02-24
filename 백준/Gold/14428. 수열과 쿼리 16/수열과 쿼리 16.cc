#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("urnoll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define INF 2e9
#define endl "\n"

// Structure
class Node {
public:
    int idx, value;

    Node() : idx(INF), value(INF) {}
    Node(const int &idx, int value) : idx(idx), value(value) {}

    bool operator<=(const Node &a) {
        if (value == a.value)
            return (idx <= a.idx);
        return (value <= a.value);
    }
};

class MinIdxSegmentTree {
public:
    explicit MinIdxSegmentTree(const vector<int> &container) {
        this->container = container;

        N = container.size();
        this->tree.resize(N * 4);

        init(0, N - 1, 1);
    }
    void update(const int &idx, int &value) {
        container[idx] = value;
        update(0, N - 1, 1, idx, value);
    }
    Node getMin(const int &start, const int &end, const int &node, const int &left, const int &right) {
        if (right < start || left > end)
            return Node();
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        Node ln = getMin(start, mid, node * 2, left, right);
        Node rn = getMin(mid + 1, end, node * 2 + 1, left, right);

        return (ln <= rn ? ln : rn);
    }
protected:
    Node init(const int &start, const int &end, const int &node) {
        if (start == end)
            return tree[node] = Node(end, container[end]);
        int mid = (start + end) / 2;
        Node ln = init(start, mid, node * 2);
        Node rn = init(mid + 1, end, node * 2 + 1);

        return tree[node] = (ln <= rn ? ln : rn);
    }
    void update(const int &start, const int &end, const int &node, const int &idx, const int &value) {
        if (idx < start || idx > end)
            return;
        if (start == end) {
            tree[node] = Node(idx, value);
            return;
        }
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, value);
        update(mid + 1, end, node * 2 + 1, idx, value);

        if (tree[node * 2].idx != INF)
            tree[node * 2].value = container[tree[node * 2].idx];
        if (tree[node * 2 + 1].idx != INF)
            tree[node * 2 + 1].value = container[tree[node * 2 + 1].idx];
        Node ln = tree[node * 2];
        Node rn = tree[node * 2 + 1];
        tree[node] = (ln <= rn ? ln : rn);
    }
private:
    int N;
    vector<int> container;
    vector<Node> tree;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> container(N);
    for (int i = 0; i < N; i++)
        cin >> container[i];
    MinIdxSegmentTree segmentTree(container);

    int M;
    cin >> M;
    while (M--) {
        int Q, I, J;
        cin >> Q >> I >> J;

        if (Q == 1)
            segmentTree.update(I - 1, J);
        else cout << segmentTree.getMin(0, N - 1, 1, I - 1, J - 1).idx + 1 << endl;
    }
}