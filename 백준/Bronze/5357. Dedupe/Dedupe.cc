#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        string str;
        cin >> str;

        string s = "";
        s += str[0];
        int len = str.length();
        for (int i = 1; i < len; i++) {
            if (str[i - 1] == str[i]) continue;
            s += str[i];
        }
        cout << s << "\n";
    }
}