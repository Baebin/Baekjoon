#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Strucutre
typedef long long ll;

class SegmentTree {
public:
    SegmentTree(const vector<ll>& container) {
        int N = container.size();
        this->container = container;
        tree.resize(N * 4);
        init(0, N - 1, 1);
    }
    ll sum(const int& start, const int& end, const int& node, const int& left, const int& right) {
        if (right < start || left > end)
            return 0;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
    }
    void update(const int& start, const int& end, const int& node, const int& idx, const ll& value) {
        if (idx < start || idx > end)
            return;
        tree[node] += value;

        // Out of Range
        if (start == end)
            return;
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, value);
        update(mid + 1, end, node * 2 + 1, idx, value);
    }
private:
    ll init(const int& start, const int& end, const int& node) {
        if (start == end)
            return tree[node] = container[end];
        int mid = (start + end) / 2;
        return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
    }
protected:
    vector<ll> container;
    vector<ll> tree;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<ll> container(N);
    SegmentTree tree(container);
    while (Q--) {
        int CMD, P; ll X;
        cin >> CMD >> P >> X;

        // Insert
        if (CMD == 1) {
            tree.update(0, N - 1, 1, P - 1, X);
            container[P - 1] += X;
        }
        else cout << tree.sum(0, N - 1, 1, P - 1, X - 1) << "\n";
    }
}