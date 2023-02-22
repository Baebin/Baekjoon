#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <bitset>
using namespace std;

// BitMask
bitset<(1 << 25)> bs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A;
    while (cin >> A) {
        if (bs[A])
            continue;
        cout << A << " ";
        bs[A] = 1;
    }
}