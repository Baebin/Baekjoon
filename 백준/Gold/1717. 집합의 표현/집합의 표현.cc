#include <iostream>
#include <vector>
using namespace std;

class Union {
public:
    Union(const int& N) {
        parent.resize(N + 1);
        for (int i = 1; i <= N; i++)
            parent[i] = i;
    }
    int find(const int& node) {
        if (parent[node] == node)
            return node;
        return parent[node] = find(parent[node]);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y)
            parent[y] = x;
    }
    bool isUnion(const int& x, const int& y) {
        return find(x) == find(y);
    }
private:
    vector<int> parent;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    Union uni(N);
    while (M--) {
        int C, A, B;
        cin >> C >> A >> B;
        if (C == 0) uni.merge(A, B);
        else cout << (uni.isUnion(A, B) ? "YES" : "NO") << '\n';
    }
}