#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int X;
    cin >> X;
    
    int N;
    cin >> N;
    while (N--) {
        int A, B;
        cin >> A >> B;
        X -= A * B;
    }
    cout << (X == 0 ? "Yes" : "No");
}