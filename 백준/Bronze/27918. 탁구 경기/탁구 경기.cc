#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int X = 0, Y = 0;
    while (N--) {
        char c;
        cin >> c;

        if (c == 'D') X++;
        else Y++;

        if (X != Y && (X - Y == 2 || Y - X == 2)) {
            cout << X << ":" << Y;
            return 0;
        }
    }
    cout << X << ":" << Y;
}