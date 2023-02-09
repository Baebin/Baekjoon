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

    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;

        vector<vector<int>> vec(2, vector<int>(N + 1));
        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= N; j++)
                cin >> vec[i][j];

        vector<vector<int>> dp(2, vector<int>(N + 1, 0));

        for (int i = 0; i <= 1; i++) {
            dp[i][0] = 0;
            dp[i][1] = vec[i][1];
        }

        for (int i = 2; i <= N; i++) {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + vec[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + vec[1][i];
        }

        cout << max(dp[0][N], dp[1][N]) << "\n";
    }
}