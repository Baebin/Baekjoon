#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

class Union {
public:
    Union(const int& N) {
        parent.resize(N);
        for (int i = 0; i < N; i++)
            parent[i] = i;
    }
    int findParent(const int& node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }
    bool mergeUnion(const int& x, const int& y) {
        int root_x = findParent(x);
        int root_y = findParent(y);

        // is Union
        if (root_x == root_y)
            return false;
        // Merge
        parent[root_y] = root_x;
        return true;
    }
private:
    vector<int> parent;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

  
    Union u(N);
    for (int i = 1; i <= M; i++) {
        int x, y;
        cin >> x >> y;

        // 집합 체크
        if (!u.mergeUnion(x, y)) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}