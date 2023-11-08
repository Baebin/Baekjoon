#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long Q, A;
    cin >> Q;
    while (Q--)
        cin >> A,
        cout << (A - (A & -A) == 0 ? 1 : 0) << '\n';
}