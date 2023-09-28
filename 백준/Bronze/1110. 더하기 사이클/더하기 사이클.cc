#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, n; cin >> N, n = N;

    int cnt = 0;
    do cnt++; while ((n = (n % 10) * 10 + ((n / 10) + (n % 10)) % 10) != N);
    cout << cnt;
}