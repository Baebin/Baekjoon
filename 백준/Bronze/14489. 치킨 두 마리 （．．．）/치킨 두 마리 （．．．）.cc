#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B, C;
    cin >> A >> B >> C;
    
    if (A + B >= 2 * C)
        cout << ((A + B) - 2 * C);
    else cout << (A + B);
}