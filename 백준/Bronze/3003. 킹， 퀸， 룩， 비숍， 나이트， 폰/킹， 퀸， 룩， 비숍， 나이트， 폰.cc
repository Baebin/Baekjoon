#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    cout << (1 - A) << " " << (1 - B)
        << " " << (2 - C) << " " << (2 - D)
        << " " <<(2 - E) << " " << (8 - F);
}