#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define MOD 1000000007

// Structure
typedef long long ll;

class SegmentTree {
public:
    SegmentTree(const vector<ll>& vec) {
        this->vec = vec;

        int N = vec.size();
        tree.resize(N * 4, 1);
        init(0, N - 1, 1);
    }
    ll multiple(const int& start, const int& end, const int& node, const int& left, const int& right) {
        // Out of Range
        if (right < start || left > end)
            return 1;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        return (multiple(start, mid, node * 2, left, right) * multiple(mid + 1, end, node * 2 + 1, left, right)) % MOD;
    }
    void update(const int& start, const int& end, const int& node, const int& idx, const ll& value) {
        if (idx < start || idx > end)
            return;
        if (start == end) {
            tree[node] = value;
            return;
        }
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, value);
        update(mid + 1, end, node * 2 + 1, idx, value);

        tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
    }
protected:
    ll init(const int& start, const int& end, const int& node) {
        if (start == end)
            return tree[node] = vec[start];
        int mid = (start + end) / 2;
        return tree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % MOD;
    }
private:
    vector<ll> vec;
    vector<ll> tree;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> vec(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];

    SegmentTree tree(vec);
    for (int i = 0; i < M + K; i++) {
        int A, B; ll C;
        cin >> A >> B >> C;
        if (A == 1)
            tree.update(0, N - 1, 1, B - 1, vec[B - 1] = C);
        else cout << tree.multiple(0, N - 1, 1, B - 1, C - 1) << "\n";
    }
}