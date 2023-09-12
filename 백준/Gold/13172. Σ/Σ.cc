#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

#define PRIME 1'000'000'007
typedef long long ll;

ll gcd(ll A, ll B) {
    while (B) {
        ll C = A % B;
        A = B;
        B = C;
    }
    return A;
}

// A^N % X
ll fastPower(ll A, ll N, const ll& X) {
    ll num = 1;
    while (N) {
        // Odd
        if (N & 1)
            num = (num * A) % X;
        A = (A * A) % X;
        N >>= 1;
    }
    return num;
}

ll convert(const ll& A, const ll& B, const ll& X = PRIME) {
    ll b_reverse = fastPower(B, X - 2, X);
    return (A * b_reverse) % X;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll M;
    cin >> M;

    ll ans = 0, N, S, G;
    while (M-- && cin >> N >> S && (G = gcd(N, S)))
        ans = (ans + convert(S / G, N / G)) % PRIME;
    cout << ans;
}