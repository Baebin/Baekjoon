#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    map<int, long long> m;
    vector<long long> sum(N + 1);

    long long cnt = 0;
    for (int i = 1; i <= N; i++) {
        cin >> sum[i];
        sum[i] += sum[i - 1];

        if (sum[i] == K)
            cnt++;

        // sum[a] - sum[b] = K
        // sum[a] - K = sum[b]

        cnt += m[sum[i] - K];
        m[sum[i]]++;
    }

    cout << cnt;
}