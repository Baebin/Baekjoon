#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Number of Lines
    int K, N, I;
    cin >> K >> N >> I;
    
    int ans = (K * N) - I;
    cout << (ans > 0 ? ans : 0);
}