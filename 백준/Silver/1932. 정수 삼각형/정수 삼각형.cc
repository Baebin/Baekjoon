#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int result = 0;
    vector<vector<int>> dp(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> dp[i][j];

            dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
            result = max(result, dp[i][j]);
        }
    }

    cout << result;
}