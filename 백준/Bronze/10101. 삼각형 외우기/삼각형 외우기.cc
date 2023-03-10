#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;
    cin >> A >> B >> C;

    if (A + B + C != 180)
        cout << "Error";
    else if (A != B && B != C && C != A)
        cout << "Scalene";
    else if (A == 60 && B == 60 && C == 60)
        cout << "Equilateral";
    else cout << "Isosceles";
}