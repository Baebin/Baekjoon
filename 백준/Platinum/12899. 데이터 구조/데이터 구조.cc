#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define MAX 2000000
#define endl "\n"

class SegmentTree {
public:
    SegmentTree(const int &N) {
        this->N = N;
        tree.resize(N * 4);
    }
    void update(const int &x) {
        update(0, N - 1, 1, x);
    }
    int queryAndDelete(const int &x) {
        return queryAndDelete(0, N - 1, 1, x);
    }
protected:
    void update(const int &start, const int &end, const int &node, const int &idx) {
        if (idx < start || idx > end)
            return;
        tree[node]++;
        if (start == end)
            return;
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx);
        update(mid + 1, end, node * 2 + 1, idx);
    }
    int queryAndDelete(const int &start, const int &end, const int &node, const int &x) {
        tree[node]--;
        if (start == end)
            return end;
        int mid = (start + end) / 2;
        if (x <= tree[node * 2])
            return queryAndDelete(start, mid, node * 2, x);
        return queryAndDelete(mid + 1, end, node * 2 + 1, x - tree[node * 2]);
    }
private:
    int N;
    vector<int> tree;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    SegmentTree tree(MAX + 1);
    while (N--) {
        int T, X;
        cin >> T >> X;
        if (T == 1)
            tree.update(X);
        else cout << tree.queryAndDelete(X) << endl;
    }
}