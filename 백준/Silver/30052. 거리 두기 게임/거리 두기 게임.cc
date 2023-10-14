#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int max_d[401][401];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, D;
    cin >> N >> M >> D;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j) {
            max_d[i][j] = max(max_d[i][j], abs(i - 1) + abs(j - 1));
            max_d[i][j] = max(max_d[i][j], abs(i - 1) + abs(j - M));
            max_d[i][j] = max(max_d[i][j], abs(i - N) + abs(j - 1));
            max_d[i][j] = max(max_d[i][j], abs(i - N) + abs(j - M));
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j) {
           if (max_d[i][j] < D)
               ans++;
        }
    }

    cout << ans << '\n';

}