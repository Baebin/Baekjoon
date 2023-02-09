#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define INF 2e9

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(3));
    vector<vector<int>> cost(N + 1, vector<int>(3));

    for (int i = 1; i <= N; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

    int result = INF;
    for (int color = 0; color < 3; color++) {
        // 1번 집 색 고정
        for (int i = 0; i < 3; i++)
            if (i == color)
                dp[1][i] = cost[1][color];
            else dp[1][i] = INF;
        // (i-1)번 집 색 != i번 집 색
        for (int i = 2; i <= N; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
        }
        // N번 집 색 != 1번 집 색
        for (int i = 0; i < 3; i++) {
            if (i == color)
                continue;
            result = min(result, dp[N][i]);
        }
    }
    cout << result;
}