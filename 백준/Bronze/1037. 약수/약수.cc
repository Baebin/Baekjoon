#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

// Declare
#define INF 2e9

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int m = INF, M = 0;
    while (N--) {
        int num;
        cin >> num;
        m = min(m, num);
        M = max(M, num);
    }
    cout << (m * M);
}