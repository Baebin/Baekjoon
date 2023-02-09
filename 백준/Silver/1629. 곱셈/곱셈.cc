#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int calculate(int a, int b, int c) {
    if (b == 1)
        return a % c;
    long long tmp = calculate(a, b / 2, c);
    if (b % 2 == 1)
        return (((tmp * tmp) % c) * a) % c;
    return (tmp * tmp) % c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;
    
    cout << calculate(A, B, C);
}