#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    cout << fixed;
    cout.precision(4);
    while (T--) {
        double value;
        cin >> value;

        string type;
        cin >> type;

        if (type == "kg")
            cout << (value * 2.2046) << " lb" << '\n';
        else if (type == "lb")
            cout << (value * 0.4536) << " kg" << '\n';
        else if (type == "l")
            cout << (value * 0.2642) << " g" << '\n';
        else cout << (value * 3.7854) << " l" << '\n';
    }
}