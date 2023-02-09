#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Declare
#define MOD 1000000007

// Strucutre
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<ll> vec(N);
    vector<ll> menu(N);

    ll tmp = 1;
    for (int i = 0; i < N; i++) {
        cin >> menu[i];
        vec[i] = (tmp - 1);
        tmp = (tmp * 2) % MOD;
    }
    sort(menu.begin(), menu.end());

    vector<ll> scoville(2);
    for (int i = N - 1; i >= 0; i--) {
        scoville[0] = (scoville[0] + vec[i] * menu[i]) % MOD;
        scoville[1] = (scoville[1] + vec[i] * menu[N - (i + 1)]) % MOD;
    }
    cout << (scoville[0] % MOD - scoville[1] % MOD + MOD) % MOD;
}