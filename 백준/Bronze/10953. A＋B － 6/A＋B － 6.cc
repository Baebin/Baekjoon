#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("urnoll-loops")

#include <iostream>
using namespace std;

// Declare
#define endl "\n"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    string str;
    while (T--) {
        cin >> str;
        cout << (str[0] + str[2] - 2 * '0') << endl;
    }
}