#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 2e9

// Structure
typedef long long ll;

class MinSegmentTree {
public:
    MinSegmentTree(const vector<ll>& vec) {
        this->vec = vec;

        int N = vec.size();
        tree.resize(N * 4);

        init(0, N - 1, 1);
    }
    ll find(const ll& start, const ll& end, const ll& node, const ll& left, const ll& right) {
        if (right < start || left > end)
            return INF;
        if (left <= start && end <= right)
            return tree[node];
        ll mid = (start + end) / 2;
        return min(find(start, mid, node * 2, left, right), find(mid + 1, end, node * 2 + 1, left, right));
    }
    void update(const ll& start, const ll& end, const ll& node, const ll& idx, const ll& value) {
        if (idx < start || idx > end)
            return;
        if (start == end) {
            tree[node] = value;
            return;
        }
        ll mid = (start + end) / 2;
        update(start, mid, node * 2, idx, value);
        update(mid + 1, end, node * 2 + 1, idx, value);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
private:
    vector<ll> vec;
    vector<ll> tree;

    ll init(const ll& start, const ll& end, const ll& node) {
        if (start == end)
            return tree[node] = vec[end];
        ll mid = (start + end) / 2;
        return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<ll> vec(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];

    int M;
    cin >> M;

    MinSegmentTree tree(vec);
    while (M--) {
        int cmd, i, j;
        cin >> cmd >> i >> j;
        
        if (cmd == 1)
            tree.update(0, N - 1, 1, i - 1, j); 
        else cout << tree.find(0, N - 1, 1, i - 1, j - 1) << '\n';
    }
}