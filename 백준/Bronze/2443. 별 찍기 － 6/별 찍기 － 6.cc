#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = N; i >= 1; i--) {
        for (int j = N - i; j >= 1; j--)
            cout << " ";
        for (int j = 1; j <= i * 2 - 1; j++)
            cout << "*";
        cout << "\n";
    }
}