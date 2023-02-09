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

    // R: pre B or G
    // G: pre R or B
    // B: pre R or G
    vector<vector<int>> dp(N + 1, vector<int>(3));

    for (int i = 1; i <= N; i++) {
        int r, g, b;
        cin >> r >> g >> b;
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b;
    }

    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);
}