#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int lcm(const int& a, const int& b) {
    return a * b / gcd(a, b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;

        int max = lcm(M, N);

        int idx;
        for (idx = x; idx <= max; idx += M) {
            if (((idx % N == 0) ? N : idx % N) == y) {
                cout << idx;
                break;
            }
        }
        if (idx > max)
            cout << -1;
        cout << "\n";
    }
}