#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <bitset>
using namespace std;

// Declare
#define BITSET_SIZE 1000000

// Structure
typedef long long ll;

void eratosthenes(bitset<BITSET_SIZE + 1> &bs, const ll &MIN, const ll &MAX) {
    bs.set();
    for (ll i = 2; i * i <= MAX; i++) {
        // ex, i = 2) (2 * 2) * mul = MIN
        ll mul = MIN / (i * i) + (MIN % (i * i) != 0);

        while (mul * (i * i) <= MAX)
            bs[mul++ * (i * i) - MIN] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll min, max;
    cin >> min >> max;

    bitset<BITSET_SIZE + 1> bs;
    eratosthenes(bs, min, max);

    cout << ((int)bs.count() - (int)((BITSET_SIZE - (max - min))));
}