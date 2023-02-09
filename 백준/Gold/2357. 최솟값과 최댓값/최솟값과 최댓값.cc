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
        tree_max.resize(N * 4);
        init(0, N - 1, 1);
    }
    pair<ll, ll> find(const int& start, const int& end, const int& node, const int& left, const int& right) {
        if (right < start || left > end)
            return { INF, 0 };
        if (left <= start && end <= right)
            return { tree_min[node], tree_max[node] };
        int mid = (start + end) / 2;
        auto data_a = find(start, mid, node * 2, left, right);
        auto data_b = find(mid + 1, end, node * 2 + 1, left, right);
        return { min(data_a.first, data_b.first), max(data_a.second, data_b.second) };
    }
private:
    void init(const int& start, const int& end, const int& node) {
        if (start == end) {
            tree_min[node] = (tree_max[node] = container[end]);
            return;
        }
        int mid = (start + end) / 2;
        init(start, mid, node * 2);
        init(mid + 1, end, node * 2 + 1);

        tree_min[node] = min(tree_min[node * 2], tree_min[node * 2 + 1]);
        tree_max[node] = max(tree_max[node * 2], tree_max[node * 2 + 1]);
    }
protected:
    vector<ll> container;
    vector<ll> tree_min;
    vector<ll> tree_max;
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

        auto data = tree.find(0, N - 1, 1, A - 1, B - 1);
        cout << data.first << " " << data.second << "\n";
    }
}