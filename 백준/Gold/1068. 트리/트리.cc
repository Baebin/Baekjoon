#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Tree
vector<vector<int>> tree;

int cnt = 0;
void DFS(const int& root, const int& node_cut) {
    if (root == node_cut)
        return;
    if (tree[root].size() == 0) {
        cnt++;
        return;
    }

    if (tree[root].size() == 1 && tree[root].front() == node_cut) {
        cnt++;
        return;
    }
    for (int node : tree[root]) {
        if (node == node_cut)
            continue;
        DFS(node, node_cut);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    tree.resize(N);

    int root;
    for (int i = 0; i < N; i++) {
        int root_tmp;
        cin >> root_tmp;

        // Validate
        if (root_tmp == -1)
            root = i;
        else tree[root_tmp].push_back(i);
    }

    int node_cut;
    cin >> node_cut;

    DFS(root, node_cut);
    cout << cnt;
}