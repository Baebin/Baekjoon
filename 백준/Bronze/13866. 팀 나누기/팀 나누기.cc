#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("urnoll-loops")

#include <iostream>
using namespace std;

int get(int A, const int& B, const int& C, const int& D) {
    A += B - (C + D);
    return (A > 0 ? A : -A);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    cout << min(min(get(A, B, C, D), get(A, C, B, D)), get(A, D, B, C));
}