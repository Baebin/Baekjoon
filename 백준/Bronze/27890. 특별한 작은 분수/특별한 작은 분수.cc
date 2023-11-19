#include <iostream>
using namespace std;

int H(const int& X, const int& n, const int& N) {
    if (n == N)
        return X;
    if (X % 2)
        return H((2 * X) ^ 6, n + 1, N);
    return H((X / 2) ^ 6, n + 1, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int X, N;
    cin >> X >> N;

    cout << H(X, 0, N);
}