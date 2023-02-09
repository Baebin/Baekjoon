#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

vector<int> dp;
vector<int> route;

int DP(const int x) {
    if (x <= 3) return x / 2;
    if (dp[x] > 0) return dp[x];

    int cnt = 1 + DP(x - 1);
    route[x] = x - 1;

    if (x % 3 == 0 && cnt > 1 + DP(x / 3)) {
        cnt = 1 + DP(x / 3);
        route[x] = x / 3;
    }
    if (x % 2 == 0 && cnt > 1 + DP(x / 2)) {
        cnt = 1 + DP(x / 2);
        route[x] = x / 2;
    }

    return dp[x] = cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X;
    cin >> X;

    dp.resize(X + 1);
    route.resize(X + 1);

    cout << DP(X) << "\n";

    cout << X << " ";
    while (route[X] > 0) {
        X = route[X];
        cout << X << " ";
    }
    if (X != 1)
        cout << 1;
}