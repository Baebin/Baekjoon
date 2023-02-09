#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
public:
    SegmentTree(const vector<int>& container) {
        int N = container.size();
        this->container = container;
        tree.resize(N * 4);
        init(0, N - 1, 1);
    }
    int multiple(const int& start, const int& end, const int& node, const int& left, const int& right) {
        if (right < start || left > end)
            return 1;
        if (left <= start && end <= right)
            return tree[node];
        int mid = (start + end) / 2;
        return multiple(start, mid, node * 2, left, right) * multiple(mid + 1, end, node * 2 + 1, left, right);
    }
    void change(const int& start, const int& end, const int& node, const int& idx, const int& value) {
        if (idx < start || idx > end)
            return;
        if (start == end) {
            tree[node] = value;
            return;
        }
        int mid = (start + end) / 2;
        change(start, mid, node * 2, idx, value);
        change(mid + 1, end, node * 2 + 1, idx, value);

        tree[node] = tree[node * 2] * tree[node * 2 + 1];
    }
private:
    int init(const int& start, const int& end, const int& node) {
        if (start == end)
            return tree[node] = container[end];
        int mid = (start + end) / 2;
        return tree[node] = init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1);
    }
protected:
    vector<int> container;
    vector<int> tree;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    while (cin >> N >> K) {
        vector<int> container(N);

        for (int i = 0; i < N; i++) {
            cin >> container[i];
            container[i] = (container[i] == 0 ? 0 : (container[i] > 0 ? 1 : -1));
        }
        SegmentTree tree(container);

        while (K--) {
            char CMD; int A, B;
            cin >> CMD >> A >> B;

            if (CMD == 'C')
                tree.change(0, N - 1, 1, A - 1, (B == 0 ? 0 : (B > 0 ? 1 : -1)));
            else {
                int mul = tree.multiple(0, N - 1, 1, A - 1, B - 1);
                if (mul == 0)
                    cout << 0;
                else if (mul > 0)
                    cout << "+";
                else cout << "-";
            }
        }
        cout << "\n";
    }
}