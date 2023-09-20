#include <iostream>
#include <iomanip>
using namespace std;

string toBinary(char octal) {
    switch (octal) {
        case '0':
            return "0";
        case '1':
            return "1";
        case '2':
            return "10";
        case '3':
            return "11";
        case '4':
            return "100";
        case '5':
            return "101";
        case '6':
            return "110";
        case '7':
        default:
            return "111";
    }
}
int main() {
    string octal;
    cin >> octal;

    int len = octal.length();
    cout << toBinary(octal[0]);
    for (int i = 1; i < len ; i++)
        cout << setfill('0') << setw(3) << toBinary((octal[i]));
}