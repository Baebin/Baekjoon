#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define endl "\n"

int getLCA(const int &A, const int &B, const vector<int> &tree) {
    vector<bool> visit(tree.size());

    int root = A;
    do {
        visit[root] = true;
        root = tree[root];
    } while (root);

    root = B;
    while (!visit[root])
        root = tree[root];
    return root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> tree(N + 1);
        while ((N--) - 1) {
            int A, B;
            cin >> A >> B;
            tree[B] = A;
        }
        int A, B;
        cin >> A >> B;
        cout << getLCA(A, B, tree) << endl;
    }
}