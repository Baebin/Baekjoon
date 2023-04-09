#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Struct
typedef long long ll;

class LazySegmentTree {
public:
    LazySegmentTree(const int &N) : N(N) {
        tree.resize(N * 4);
        lazy.resize(N * 4);
    }
protected:
    int N;
    int sum(const int &start, const int &end, const int &node, const int &left, const int &right) {
        update_lazy(start, end, node);
        if (right < start || left > end)
            return 0;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        return sum(start, mid, node * 2, left, right)
            + sum(mid + 1, end, node * 2 + 1, left, right);
    }
    void update(const int &start, const int &end, const int &node, const int &left, const int &right, const int &value) {
        update_lazy(start, end, node);
        if (right < start || left > end)
            return;
        if (left <= start && end <= right) {
            tree[node] += value * (end - start + 1);
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
    void update_lazy(const int &start, const int &end, const int &node) {
        if (lazy[node] == 0)
            return;
        tree[node] += lazy[node] * (end - start + 1);
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
private:
    vector<ll> tree;
    vector<ll> lazy;
};

class EggplantTree : LazySegmentTree {
public:
    EggplantTree(const int &N, const int &K) : LazySegmentTree(N), K(K), STACK(0) {}
    int sum(const int &left, const int &right) {
        return LazySegmentTree::sum(0, N - 1, 1, left, right);
    }
    void update(const int &left, const int &right, const int &value) {
        LazySegmentTree::update(0, N - 1, 1, left, right, value);
    }
    bool check(const int &DAY, int &T, const int &R) {
        if ((STACK += R) <= K) {
            return false;
        }
        do {
            if (sum(T, T) > K) {
                cout << DAY << " " << T;
                return true;
            }
        } while (--T);
        return false;
    }
private:
    int K, STACK;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    EggplantTree tree(N + 1, K);
    for (int i = 1; i <= M; i++) {
        int T, R;
        cin >> T >> R;
        tree.update(1, T, R);

        if (tree.check(i, T, R))
            return 0;
    }
    cout << -1;
}