#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    int len = str.length();
    if (len == 2) cout << ((str[0] - '0') + (str[1] - '0'));
    else if (len == 3 && str[1] == '0') cout << ((str[0] - '0') * 10 + (str[1] - '0') + (str[2] - '0'));
    else if (len == 3 && str[2] == '0') cout << ((str[0] - '0') + (str[1] - '0') * 10 + (str[2] - '0'));
    else if (len == 4) cout << ((str[0] - '0') * 10 + (str[1] - '0') + (str[2] - '0') * 10 + (str[3] - '0'));
}