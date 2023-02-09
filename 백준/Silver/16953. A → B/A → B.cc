#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

// Declare
#define INF 2e9

// Structure
typedef long long ll;

// Count
ll cnt = INF;

void DFS(const ll& A, const ll& B, const ll& depth) {
    if (A == B) {
        cnt = min(cnt, depth);
        return;
    }
    if (A > B)
        return;
    DFS(A * 2, B, depth + 1);
    DFS(A * 10 + 1, B, depth + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll A, B;
    cin >> A >> B;

    DFS(A, B, 1);

    if (cnt == INF)
        cout << -1;
    else cout << cnt;
}