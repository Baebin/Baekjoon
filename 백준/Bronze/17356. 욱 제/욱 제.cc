#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double A, B;
    cin >> A >> B;

    double M = (B - A) / 400;

    cout.precision(4);
    cout << fixed << 1 / (1 + pow(10, M));
}