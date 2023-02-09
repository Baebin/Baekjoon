#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Structure
typedef long long ll;

class Union {
public:
    Union(int N) {
        parent.resize(N + 1);
        weight.resize(N + 1);
        for (int i = 1; i <= N; i++)
            parent[i] = i;
    }
    int findParent(const int& node) {
        if (parent[node] == node)
            return node;
        // find Parent
        int p = findParent(parent[node]);

        // Weight difference between Root and this Node
        weight[node] += weight[parent[node]];
        return parent[node] = p;
    }
    void merge(const int& x, const int& y, const int& k) {
        int root_x = findParent(x);
        int root_y = findParent(y);

        // is Union
        if (root_x == root_y)
            return;
        // Merge
        parent[root_y] = root_x;
        weight[root_y] = (weight[x] + k) - weight[y];
    }
    ll getWeight(const int& x, const int& y) { return weight[y] - weight[x]; }
    bool isUnion(const int& x, const int& y) { return (findParent(x) == findParent(y)); }
private:
    vector<ll> weight;
    vector<int> parent;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        int N, M;
        cin >> N >> M;

        // End
        if (N == 0 && M == 0)
            return 0;

        Union u(N);
        while (M--) {
            char c;
            cin >> c;

            int a, b;
            cin >> a >> b;
            if (c == '!') {
                int w;
                cin >> w;
                u.merge(a, b, w);
                continue;
            }
            if (!u.isUnion(a, b))
                cout << "UNKNOWN" << "\n";
            else cout << u.getWeight(a, b) << "\n";
        }
    }
}