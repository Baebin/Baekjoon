#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    double X, Y;
    while (cin >> X >> Y) {
        if (X == 0 || Y == 0) cout << "AXIS\n";
        else if (X > 0 && Y > 0) cout << "Q1\n";
        else if (X < 0 && Y > 0) cout << "Q2\n";
        else if (X < 0 && Y < 0) cout << "Q3\n";
        else cout << "Q4\n";
    }
};