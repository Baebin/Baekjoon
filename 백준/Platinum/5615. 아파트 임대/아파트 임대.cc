#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

#define MUL(X, Y, M) (X * Y) % M

typedef unsigned long long ull;

class MillerRabin {
public:
    bool isPrime(const ull& N) {
        for (const ull& prime : primes)
            if (!checkPrime(N, prime))
                return false;
        return true;
    }
protected:
    ull fastPower(ull X, ull Y, const ull& M) {
        ull power = 1;
        while (Y) {
            if (Y % 2)
                power = MUL(power, X, M);
            X = MUL(X, X, M);
            Y >>= 1;
        }
        return power;
    }
    bool checkPrime(const ull& N, const ull& A) {
        if (A % N == 0)
            return true;
        ull K = N - 1;
        while (true) {
            ull power = fastPower(A, K, N);
            if (power == N - 1)
                break;
            if (K % 2)
                return (power == 1);
            K >>= 1;
        }
        return true;
    }
private:
    const vector<ull> primes = { 2, 7, 61 };
};

int main() {
    int N;
    cin >> N;

    ull S; int ans = 0;
    MillerRabin millerRabin;
    while (N--) cin >> S, ans += millerRabin.isPrime(2 * S + 1);
    cout << ans;
}