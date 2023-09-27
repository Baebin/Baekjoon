#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string N;
    while (cin >> N) {
        if (N == "0") break;
        int len = N.length();
        int sum = len + 1;
        while (len--) {
            switch (N[len]) {
                case '0':
                    sum += 4;
                    break;
                case '1':
                    sum += 2;
                    break;
                default:
                    sum += 3;
                    break;
            }
        }
        cout << sum << '\n';
    }
}