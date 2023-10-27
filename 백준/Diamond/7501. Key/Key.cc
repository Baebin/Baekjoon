#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

#define mul(X, Y, M) (((ui128)X * Y) % M)

// Structure
typedef unsigned long long ull;
typedef unsigned __int128 ui128;

class MillerRabin {
public:
    // Check N
    bool isPrime(const ull& N) {
        for (const ull& prime : primes)
            if (!checkPrime(N, prime))
                return false;
        return true;
    }
protected:
    // X ^ Y % M
    ull fastPower(ull X, ull Y, const ull& M) {
        ull power = 1;
        while (Y) {
            if (Y % 2)
                power = mul(X, power, M);
            X = mul(X, X, M);
            Y >>= 1;
        }
        return power;
    }
    bool checkPrime(const ull& N, const ull& A) {
        // Prime Check
        if (A % N == 0)
            return true;
        ull K = N - 1;
        while (true) {
            ull power = fastPower(A, K, N);
            // A ^ K % N == 1 || -1
            if (K % 2)
                return (power == 1 || power == N - 1);
            // A ^ K % N == -1
            if (power == N - 1)
                break;
            K >>= 1;
        }
        return true;
    }
private:
    const vector<ull> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
};

int main() {
    ull A, B;
    cin >> A >> B;

    MillerRabin millerRabin;
    for (ull i = A; i <= B; i++)
        if (i == 9 || millerRabin.isPrime(i))
            cout << i << ' ';
}