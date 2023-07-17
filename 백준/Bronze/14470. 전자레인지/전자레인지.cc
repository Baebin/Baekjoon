#include <iostream>
using namespace std;

int main() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    
    if (A < 0) cout << (((-1) * A * C) + D + E * (B));
    else cout << E * (B - A);
}
