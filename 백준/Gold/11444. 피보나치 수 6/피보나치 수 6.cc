#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <map>
using namespace std;

// Declare
#define MOD 1000000007

// Structure
typedef long long ll;

// Memorization
map<ll, ll> vec;

ll fibo(const ll& N) {
    if (N == 0) return 0;
    if (N <= 2) return 1;
    if (vec[N]) return vec[N];

    // fibo(2n) = fibo(n) * (2fibo(n-1) + fibo(n))
    // fibo(2n+1) = fibo(n+1) ^ 2 + fibo(n) ^ 2
    
    // fibo(n) = fibo(n/2) * (2fibo(n/2-1) + fibo(n/2))
    //         = fibo((n+1)/2) ^ 2 + fibo((n-1)/2) & 2

    if (N % 2 == 1)
        return vec[N] = (fibo((N + 1) / 2) * fibo((N + 1) / 2) + fibo((N - 1) / 2) * fibo((N - 1) / 2)) % MOD;
    return vec[N] = (fibo(N / 2) * (2 * fibo(N / 2 - 1) + fibo(N / 2))) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N;
    cin >> N;

    cout << fibo(N);
}   