#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        string K;
        cin >> K;

        if ((K.back() - '0') % 2)
            cout << "odd" << '\n';
        else cout << "even" << '\n';
    }
}