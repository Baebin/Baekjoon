#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N1, K1, N2, K2;
    cin >> N1 >> K1 >> N2 >> K2;
    cout << ((N1 * K1) + (N2 * K2));
}