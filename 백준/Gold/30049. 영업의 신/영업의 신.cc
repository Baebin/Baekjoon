#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll p[301][10001];
ll q[301];
pair<ll, int> mm[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            int a, b;
            cin >> a >> b;
            p[i][a] = b;
        }
    }
    for (int i = 1; i <= m; ++i) {
        ll max_p = 0;
        int person = 0;
        for (int j = 1; j <= n; ++j) {
            if (p[j][i] > max_p) {
                max_p = p[j][i];
                person = j;
            }
        }
        mm[i] = {max_p, person};
        q[person]++;
    }
    int t;
    cin >> t;
    while (t--) {
        int ans = 0;
        int a, b, c;
        cin >> a >> b >> c;
        p[a][b] += c;
        if (mm[b].first < p[a][b]) {
            q[a]++;
            q[mm[b].second]--;
            mm[b].first = p[a][b];
            mm[b].second = a;
        }
        for (int i = 1; i <= n; ++i) {
            if (q[i] == k) ans++;
        }
        cout << ans << "\n";
    }
}