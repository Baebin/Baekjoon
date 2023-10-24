#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define abs(X) ((X) > (0) ? (X) : -(X))
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

class PollardRho {
public:
    explicit PollardRho(const ull& N) : N(N) { init(); }
    vector<ull> getPrimes() { return primes; }
protected:
    void init() {
        while (N != 1) {
            ull prime = find(N);
            primes.emplace_back(prime);
            N /= prime;
        }
    }
    ull find(const ull& N) {
        if (N % 2 == 0)
            return 2;
        if (millerRabin.isPrime(N))
            return N;
        ull X, Y, C, G = N;
        auto f = [&](const ull& A) { return (mul(A, A, N) + C) % N; };
        do {
            if (G == N) {
                X = Y = rand() % (N - 2) + 2;
                C = rand() % 10 + 1;
            }
            X = f(X), Y = f(f(Y));
            G = gcd(abs(X - Y), N);
        } while (G == 1);
        if (millerRabin.isPrime(G))
            return G;
        return find(G);
    }
    ull gcd(ull A, ull B) {
        if (A < B)
            swap(A, B);
        while (B) {
            ull R = A % B;
            A = B;
            B = R;
        }
        return A;
    }
private:
    ull N;
    vector<ull> primes;
    MillerRabin millerRabin;
};

int main() {
    ull N;
    cin >> N;

    vector<ull> primes = PollardRho(N).getPrimes();
    sort(primes.begin(), primes.end());
    for (const ull& P : primes)
        cout << P << '\n';
}