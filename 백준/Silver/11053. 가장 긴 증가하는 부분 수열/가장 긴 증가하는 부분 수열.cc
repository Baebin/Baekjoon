#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A;
    cin >> A;
    vector<int> dp(A);
    vector<int> vec(A);

    int cnt = 0;
    for (int i = 0; i < A; i++) {
        cin >> vec[i];
        dp[i] = 1;

        for (int j = 0; j < i; j++)
            if (vec[i] > vec[j])
                dp[i] = max(dp[i], dp[j] + 1);
        cnt = max(cnt, dp[i]);
    }

    cout << cnt;
}