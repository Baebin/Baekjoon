#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int Y = 0, M = 0;
    while (N--) {
        int n;
        cin >> n;
        Y += ((n / 30) + 1) * 10;
        M += ((n / 60) + 1) * 15;
    }

    if (Y == M)
        cout << "Y M " << Y;
    else if (Y < M)
        cout << "Y " << Y;
    else cout << "M " << M;
}