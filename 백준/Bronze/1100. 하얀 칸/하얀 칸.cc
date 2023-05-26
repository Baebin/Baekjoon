#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str; int cnt = 0;
    for (register int i = 1; i <= 8; i++) {
        cin >> str;
        bool white = (i % 2);

        for (const char& c : str) {
            if (c == 'F' && white)
                cnt++;
            white = !white;
        }
    }
    cout << cnt;
}