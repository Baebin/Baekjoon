#include <iostream>
#include <cmath>
using namespace std;

// Structure
typedef long long ll;

/*
    100(Y + ANS) / (X + ANS) = (Z + 1) = ZZ
    100(Y + ANS) = ZZ(X + ANS)
    ANS(100 - ZZ) = ZZ(X) - 100(Y)
    ANS = (ZZ(X) - 100(Y)) / (100 - ZZ)
*/

int main() {
    ll X, Y, ZZ;
    cin >> X >> Y, ZZ = ((100 * Y) / X) + 1;
    cout << (ZZ < 100 ? (ll)ceil((double)(ZZ * (X) - 100 * (Y)) / (100 - ZZ)) : -1);
}