#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define MAX 1000000
#define endl "\n"

class SegmentTree {
public:
    SegmentTree(const int &N) : N(N) { tree.resize(N * 4); }
    void update(const int &start, const int &end, const int &node, const int &idx, const int &value) {
        if (idx < start || idx > end)
            return;
        tree[node] += value;
        if (start == end)
            return;
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, value);
        update(mid + 1, end, node * 2 + 1, idx, value);
    }
    int queryAndDelete(const int &start, const int &end, const int &node, const int &B) {
        tree[node]--;
        if (start == end)
            return end;
        int mid = (start + end) / 2;
        if (B <= tree[node * 2])
            return queryAndDelete(start, mid, node * 2, B);
        return queryAndDelete(mid + 1, end, node * 2 + 1, B - tree[node * 2]);
    }
protected:
    int N;
    vector<int> tree;
};

class CandyBox : SegmentTree {
public:
    CandyBox(const int &N) : SegmentTree(N) {}
    void add(const int &B, const int &C) { SegmentTree::update(1, SegmentTree::N - 1, 1, B, C); }
    int pop(const int &B) { return SegmentTree::queryAndDelete(1, SegmentTree::N - 1, 1, B); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    CandyBox box(MAX + 1);
    while (N--) {
        int A, B;
        cin >> A >> B;

        if (A == 1)
            cout << box.pop(B) << endl;
        else {
            int C;
            cin >> C;
            box.add(B, C);
        }
    }
}