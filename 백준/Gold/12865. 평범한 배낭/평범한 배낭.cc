#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

struct Item {
    int weight, value;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<Item> backpack(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> backpack[i].weight >> backpack[i].value;

    vector<vector<int>> dp(N + 1, vector<int>(K + 1));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= K; j++)
            if (j >= backpack[i].weight)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - backpack[i].weight] + backpack[i].value);
            else dp[i][j] = dp[i - 1][j];
    cout << dp[N][K];
}