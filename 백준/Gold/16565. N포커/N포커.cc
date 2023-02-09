#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Declare
#define MOD 10007

// nCk
const int K = 52;
vector<vector<int>> nCk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    nCk.resize(K + 1, vector<int>(K + 1));
    for (int i = 0; i <= K; i++) {
        nCk[i][0] = nCk[i][i] = 1;
        for (int j = 1; j < i; j++)
            nCk[i][j] = (nCk[i][i - j] = (nCk[i - 1][j - 1] + nCk[i - 1][j]) % MOD);
    }

    int ans = 0, idx = 0;
    while ((idx += 4) <= N)
        ans = (ans + (nCk[13][idx / 4] * nCk[52 - idx][N - idx]) * ((idx / 4) % 2 == 1 ? 1 : -1)) % MOD;
    cout << ((ans < 0 ? MOD : 0) + ans) % MOD;
}