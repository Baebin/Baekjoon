#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string num = "";
    string expression;
    cin >> expression;

    int sum = 0;
    int weight = 1;

    int len = expression.length();
    for (int i = 1; i <= len; i++) {
        char c = expression[i - 1];

        if (i == len)
            num += c;
        if (c == '+' || c == '-' || i == len) {
            sum += stoi(num) * weight;
            num = "";
        }
        else num += c;

        if (c == '-')
            weight = -1;
    }

    cout << sum;
}