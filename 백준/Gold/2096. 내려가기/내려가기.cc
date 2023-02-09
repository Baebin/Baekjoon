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

    int a, b, c;
    cin >> a >> b >> c;

    // Max, Min
    vector<vector<int>> dp(2, vector<int>(3));
    dp = { { a, b, c }, { a, b, c } };

    vector<vector<int>> tmp;
    for (int i = 1; i < N; i++) {
        cin >> a >> b >> c;
        tmp = dp;

        dp[0][0] = max(tmp[0][0], tmp[0][1]) + a;
        dp[0][1] = max(tmp[0][0], max(tmp[0][1], tmp[0][2])) + b;
        dp[0][2] = max(tmp[0][1], tmp[0][2]) + c;

        dp[1][0] = min(tmp[1][0], tmp[1][1]) + a;
        dp[1][1] = min(tmp[1][0], min(tmp[1][1], tmp[1][2])) + b;
        dp[1][2] = min(tmp[1][1], tmp[1][2]) + c;
    }
    cout << max(dp[0][0], max(dp[0][1], dp[0][2])) << " "
         << min(dp[1][0], min(dp[1][1], dp[1][2]));
}   