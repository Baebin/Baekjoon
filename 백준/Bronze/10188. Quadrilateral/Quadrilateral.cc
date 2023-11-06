#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int X, Y;
        cin >> X >> Y;
        while (Y--) {
            for (int i = 0; i < X; i++)
                cout << "X";
            cout << '\n';
        }
        cout << '\n';
    }
}