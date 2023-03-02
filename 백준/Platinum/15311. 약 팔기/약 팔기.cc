#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    cout << 2000 << "\n";
    for (int i = 1; i <= 2000; i++)
        cout << (i <= 1000 ? 1 : 1000) << " ";
}