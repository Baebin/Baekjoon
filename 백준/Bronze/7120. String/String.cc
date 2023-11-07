#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;

    str += "!";
    int len = str.length() - 1;
    for (int i = 0; i < len; i++)
        if (str[i] != str[i + 1])
            cout << str[i];
}