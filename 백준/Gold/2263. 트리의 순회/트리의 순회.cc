#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Inorder Index
vector<int> idx;

// Left, (Root), Right
vector<int> inorder;

// Left, Right, (Root)
vector<int> postorder;

// DFS
void preorder(int in_start, int in_end, int post_start, int post_end) {
    // Out of Range
    if (in_start > in_end || post_start > post_end)
        return;
    int root = postorder[post_end];
    int index = idx[root];
    int left_cnt = index - in_start;

    cout << root << " ";
    // Left
    preorder(in_start, index - 1, post_start, post_start + left_cnt - 1);
    // Right
    preorder(index + 1, in_end, post_start + left_cnt, post_end - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    idx.resize(N + 1);
    inorder.resize(N + 1);
    postorder.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    for (int i = 1; i <= N; i++)
        cin >> postorder[i];
   
    // Root: postorder[N]
    preorder(1, N, 1, N);
}