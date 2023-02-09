#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define INF 2e9

// Structure
typedef long long ll;

class SegmentTree {
public:
    SegmentTree(const vector<ll>& container) {
        int N = container.size();
        this->container = container;
        tree_min.resize(N * 4);
        init(0, N - 1, 1);
    }
    ll find(const int& start, const int& end, const int& node, const int& left, const int& right) {
        if (right < start || left > end)
            return INF;
        if (left <= start && end <= right)
            return tree_min[node];
        int mid = (start + end) / 2;
        return min(find(start, mid, node * 2, left, right), find(mid + 1, end, node * 2 + 1, left, right));
    }
private:
    void init(const int& start, const int& end, const int& node) {
        if (start == end) {
            tree_min[node] = container[end];
            return;
        }
        int mid = (start + end) / 2;
        init(start, mid, node * 2);
        init(mid + 1, end, node * 2 + 1);
        tree_min[node] = min(tree_min[node * 2], tree_min[node * 2 + 1]);
    }
protected:
    vector<ll> container;
    vector<ll> tree_min;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<ll> container(N);
    for (int i = 0; i < N; i++)
        cin >> container[i];

    SegmentTree tree(container);
    while (M--) {
        int A, B;
        cin >> A >> B;
        cout << tree.find(0, N - 1, 1, A - 1, B - 1) << "\n";
    }
}