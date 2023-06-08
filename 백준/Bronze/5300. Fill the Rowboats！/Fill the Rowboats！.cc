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

    for (int i = 1; i <= N; i++) {
        if (i / 6 && i % 6 == 1)
            cout << "Go! ";
        cout << i << " ";
    }
    cout << "Go!";
}