#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

class Union {
public:
    Union(const int& N) { parent.resize(N, -1); }
    int findParent(const int& node) {
        if (parent[node] == -1) return node;
        return parent[node] = findParent(parent[node]);
    }
    void merge(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        // is Union
        if (x == y)
            return;
        // Merge
        parent[y] = x;
    }
    bool isUnion(const int& x, const int& y) { return findParent(x) == findParent(y); }
private:
    vector<int> parent;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int num;
    cin >> num;

    // Init
    int person = 0;
    if (num-- > 0) cin >> person;

    Union u(N + 1);
    while (num-- > 0) {
        int tmp;
        cin >> tmp;
        u.merge(person, tmp);
    }

    vector<vector<int>> vec(M);
    for (int i = 0; i < M; i++) {
        cin >> num;

        vec[i].resize(num);
        bool isUnion = false;

        int p;
        while (num--) {
            cin >> p;

            // Validate
            if (u.isUnion(person, p))
                isUnion = true;
            vec[i][num] = p;
        }

        // Merge
        for (int _p : vec[i])
            if (isUnion)
                u.merge(person, _p);
            else u.merge(p, _p);
    }

    int cnt = 0;
    for (vector<int> party : vec) {
        // Validate
        if (person == -1) {
            cnt++;
            continue;
        }

        bool isUnion = false;
        for (int _p : party) {
            if (!u.isUnion(person, _p))
                continue;
            isUnion = true;
            break;
        }
        if (!isUnion)
            cnt++;
    }
    cout << cnt;
}