#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define MAX 55

// Bit Count
vector<long long> bits(MAX);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Init
    bits[0] = 1;
    for (long long i = 1; i < MAX; i++)
        bits[i] = bits[i - 1] * 2 + (1LL << i);

    long long A, B;
    cin >> A >> B;

    auto bit = [](long long a) {
        // 0번 비트
        long long sum = a & 1;

        for (int i = MAX - 1; i > 0; i--) {
            // 최상위 비트
            if (a & (1LL << i)) {
                sum += bits[i - 1] + (a - (1LL << i) + 1);
                a -= (1LL << i);
            }
        }
        return sum;
    };

    // (A-1) ~ B
    cout << bit(B) - bit(A - 1);
}