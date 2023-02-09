#include <iostream>
#include <vector>
using namespace std;

int dp(int &N) {
    /*
    1, 4, 9, 16, 25, 36, ...
    f(5) = dp[1] + dp[4];
    f(6) = dp[4] + dp[2];
    f(10) = dp[9] + dp[1];
    f(10) != dp[4] + dp[6];
    dp[n] = dp[i^2] + dp[n-i];
    */

    vector<int> vec(N + 1);

    for (int n = 1; n <= N; n++) {
        vec[n] = vec[n - 1] + 1;
        for (int j = 1; j * j <= n; j++)
            vec[n] = min(vec[n], 1 + vec[n - j * j]);
    }

    return vec[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    cout << dp(N);
}