#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 

#include <iostream>
using namespace std;

// Declare
#define INF 1e9

// Structure
typedef long long ll;

// ax + by = gcd(a, b)
// ax % b + 0 = 1 % b

ll exEuclidean(const ll& A, const ll& B) {
    ll a = A, b = B;
    ll x1 = 1, x2 = 0;

    while (b != 0) {
        ll quotient = (a / b);
        ll tmp = (a % b);
        a = b;
        b = tmp;

        tmp = x1 - quotient * x2;
        x1 = x2, x2 = tmp;
    }

    // 서로소 체크
    if (a != 1)
        return -1;
    while (x1 * A < B)
        x1 += B;
    return x1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        ll K, C;
        cin >> K >> C;

        if (C == 1) {
            // Out of Range
            if (K == INF)
                cout << "IMPOSSIBLE" << "\n";
            else cout << K + 1 << "\n";
            continue;
        }

        ll x = exEuclidean(C, K);
        if (x == -1)
            cout << "IMPOSSIBLE" << "\n";
        else cout << x << "\n";
    }
}