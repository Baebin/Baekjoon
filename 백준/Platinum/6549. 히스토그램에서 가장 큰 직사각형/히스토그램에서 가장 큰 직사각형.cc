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
    MinIdxSegmentTree(const vector<int>& container) {
        this->container = container;

        N = container.size();
        tree.resize(N * 4);

        init(0, N - 1, 1);
    }
    int getMin(const int& start, const int& end, const int& node, const int& left, const int& right) {
        if (right < start || left > end)
            return INF;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        int lh = getMin(start, mid, node * 2, left, right);
        int rh = getMin(mid + 1, end, node * 2 + 1, left, right);

        if (lh == INF)
            return rh;
        if (rh == INF)
            return lh;
        return (container[lh] <= container[rh] ? lh : rh);
    }
protected:
    int N; vector<int> container;
    int init(const int& start, const int& end, const int& node) {
        if (start == end)
            return tree[node] = end;
        int mid = (start + end) / 2;
        int lh = init(start, mid, node * 2);
        int rh = init(mid + 1, end, node * 2 + 1);

        return tree[node] = (container[lh] <= container[rh] ? lh : rh);
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
        int idx = getMin(0, this->N - 1, 1, start, end);
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

    while (true) {
        int N;
        cin >> N;

        if (N == 0)
            return 0;
        vector<int> container(N);
        for (int i = 0; i < N; i++)
            cin >> container[i];
        cout << RectangleFinder(container).getMaxArea(0, N - 1) << "\n";
    }
}