#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("urnoll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    const int N = n;
    do {
        for (int i = N; i > n; i--)
            cout << " ";
        for (int i = 0; i < n; i++)
            cout << "*";
        if (n > 1) cout << "\n";
    } while (--n);
}