#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroint-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int zero = 0, one = 0;
    bool was_zero = false, was_one = false;
    for (char c : str) {
        if (c == '0') {
            if (!was_zero) {
                was_one = false;
                was_zero = true;
                zero++;
            }
            continue;
        }
        if (!was_one) {
            was_one = true;
            was_zero = false;
            one++;
        }
    }
    cout << min(zero, one);
}