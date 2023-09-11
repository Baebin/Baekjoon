#include <iostream>
using namespace std;

int main() {
    double A, B, C, D;
    cin >> A >> B >> C >> D;

    double a = (A / C) + (B / D);
    double b = (C / D) + (A / B);
    double c = (D / B) + (C / A);
    double d = (B / A) + (D / C);

    double m = max(max(a, b), max(c, d));
    if (m == a) cout << 0;
    else if (m == b) cout << 1;
    else if (m == c) cout << 2;
    else cout << 3;
}