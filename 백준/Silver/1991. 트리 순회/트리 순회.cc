#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define ROOT 'A'

// Tree
vector<vector<char>> tree;

void predorder(char node) {
    if (node == '.')
        return;
    cout << node;
    predorder(tree[node - ROOT][0]);
    predorder(tree[node - ROOT][1]);
}

void inorder(char node) {
    if (node == '.')
        return;
    inorder(tree[node - ROOT][0]);
    cout << node;
    inorder(tree[node - ROOT][1]);
}

void postorder(char node) {
    if (node == '.')
        return;
    postorder(tree[node - ROOT][0]);
    postorder(tree[node - ROOT][1]);
    cout << node;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    tree.resize(N, vector<char>(2));
    while (N--) {
        char A;
        cin >> A;
        cin >> tree[A - ROOT][0];
        cin >> tree[A - ROOT][1];
    }

    predorder(ROOT);
    cout << "\n";

    inorder(ROOT);
    cout << "\n";

    postorder(ROOT);
    cout << "\n";
}