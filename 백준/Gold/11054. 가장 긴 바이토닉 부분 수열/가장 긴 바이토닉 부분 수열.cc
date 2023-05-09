#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // LIS - default, reverse
    int cnt = 0;
    vector<vector<int>> dp(N, vector<int>(2));

    // Input
    vector<int> vec(N);
    for (register int i = 0; i < N; i++) {
        cin >> vec[i];

        // LIS - default
        dp[i][0] = 1;
        for (register int j = 0; j < i; j++)
            if (vec[i] > vec[j])
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
    }

    // LIS - reverse
    for (register int i = N - 1; i >= 0; i--) {
        dp[i][1] = 1;
        for (register int j = N - 1; j > i; j--)
            if (vec[i] > vec[j])
                dp[i][1] = max(dp[i][1], dp[j][1] + 1);
        // Bitonic Subsequence
        cnt = max(cnt, dp[i][0] + dp[i][1] - 1);
    }
    cout << cnt;
}