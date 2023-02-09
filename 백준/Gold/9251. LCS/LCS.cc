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

    /*
    . A C A Y K P
    C 0 1 1 1 1 1
    A 1 1 2 2 2 2
    P 1 1 2 2 2 3
    C 1 2 2 2 2 3
    A 1 2 3 3 3 3
    K 1 2 3 3 4 4
    */

    string str_a, str_b;
    cin >> str_a >> str_b;

    int len_a = str_a.length();
    int len_b = str_b.length();

    vector<vector<int>> dp(len_a + 1, vector<int>(len_b + 1));
    for (int i = 1; i <= len_a; i++) {
        for (int j = 1; j <= len_b; j++) {
            if (str_a[i - 1] == str_b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[len_a][len_b];
}