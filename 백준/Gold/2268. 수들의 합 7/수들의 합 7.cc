#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Structure
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
    void modify(const int& start, const int& end, const int& node, const int& idx, const ll& value) {
        if (idx < start || idx > end)
            return;
        tree[node] += value;
        if (start == end)
            return;
        int mid = (start + end) / 2;
        modify(start, mid, node * 2, idx, value);
        modify(mid + 1, end, node * 2 + 1, idx, value);
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

    int N, M;
    cin >> N >> M;

    vector<ll> container(N);
    SegmentTree tree(container);

    while (M--) {
        int CMD, A, B;
        cin >> CMD >> A >> B;

        // Modify
        if (CMD) {
            tree.modify(0, N - 1, 1, A - 1, B - container[A - 1]);
            container[A - 1] = B;
        }
        // Print the Sum
        else {
            if (A > B) swap(A, B);
            cout << tree.sum(0, N - 1, 1, A - 1, B - 1) << "\n";
        }
    }
}