#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    while (getline(cin, str)) {
        if (str == "END")
            return 0;
        int len = str.length();
        for (register int i = len - 1; i >= 0; i--)
            cout << str[i];
        cout << "\n";
    }
}