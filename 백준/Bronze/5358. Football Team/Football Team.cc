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
        for (const char& c: str) {
            switch (c) {
                case 'i':
                    cout << "e";
                    break;
                case 'e':
                    cout << "i";
                    break;
                case 'I':
                    cout << "E";
                    break;
                case 'E':
                    cout << "I";
                    break;
                default:
                    cout << c;
                    break;
            }
        }
        cout << "\n";
    }
}