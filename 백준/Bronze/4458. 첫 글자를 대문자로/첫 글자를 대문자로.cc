#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    cin.ignore(100, '\n');
    while (N--) {
        string str;
        getline(cin, str);

        bool isFirst = true;
        if ('a' <= str[0] && str[0] <= 'z')
            str[0] -= ('a' - 'A');
        cout << str << '\n';
    }
}