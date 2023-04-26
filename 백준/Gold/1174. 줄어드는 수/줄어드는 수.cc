#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure
typedef long long ll;

vector<ll> vec;
void dfs(const ll& N, const int& idx) {
    // Depth Limit
    if (N > 9876543210) return;

    vec.emplace_back(N);
    for (register int i = 0; i <= N % 10 - 1; i++)
        dfs(N * 10 + i, idx);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // fast
    if (N <= 10) {
        cout << N - 1;
        return 0;
    }

    // dfs
    for (register int i = 0; i <= 9; i++)
        dfs(i, N);

    // ans
    if (N <= vec.size()) {
        sort(vec.begin(), vec.end());
        cout << vec[N - 1];
    } else cout << -1;
}