#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Tree
int idx = 0;
vector<int> preorder(10000);

// Root, Left, Right
void postorder(const int& start, const int& end) {
    if (start >= end)
        return;
    int idx = start;
    while (++idx < end)
        if (preorder[start] < preorder[idx])
            break;
    postorder(start + 1, idx);
    postorder(idx, end);
    cout << preorder[start] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    while (cin >> num)
        preorder[idx++] = num;
    postorder(0, idx);
}