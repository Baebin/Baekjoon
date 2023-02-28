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

class MinIdxSegmentTree {
public:
    explicit MinIdxSegmentTree(const vector<int> &container) {
        this->container = container;

        N = container.size();
        tree.resize(N * 4);

        init(0, N - 1, 1);
    }
    int find(const int &left, const int &right) {
        return find(0, N - 1, 1, left, right);
    }
protected:
    int N; vector<int> container;
    int init(const int &start, const int &end, const int &node) {
        if (start == end)
            return tree[node] = start;
        int mid = (start + end) / 2;
        int l = init(start, mid, node * 2);
        int r = init(mid + 1, end, node * 2 + 1);

        return tree[node] = (container[l] <= container[r] ? l : r);
    }
    int find(const int &start, const int &end, const int &node, const int &left, const int &right) {
        if (right < start || left > end)
            return INF;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        int l = find(start, mid, node * 2, left, right);
        int r = find(mid + 1, end, node * 2 + 1, left, right);

        if (l == INF)
            return r;
        if (r == INF)
            return l;
        return (container[l] <= container[r] ? l : r);
    }
private:
    vector<int> tree;
};

class RectangleFinder : public MinIdxSegmentTree {
public:
    RectangleFinder(const vector<int>& container) : MinIdxSegmentTree(container) {
        this->area = 0;
    }
    ll getMaxArea(const int& start, const int& end) {
        findMaxArea(start, end);
        return area;
    }
protected:
    void findMaxArea(const int& start, const int& end) {
        if (start > end)
            return;
        int idx = MinIdxSegmentTree::find(start, end);
        ll mx = (end - start + 1), mh = this->container[idx];

        area = max(area, mx * mh);
        findMaxArea(start, idx - 1);
        findMaxArea(idx + 1, end);
    }
private:
    ll area;
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
    cout << RectangleFinder(container).getMaxArea(0, N - 1) << "\n";
}