#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int A;
    cin >> A;

    if (A >= 620)
        cout << "Red";
    else if (A >= 590)
        cout << "Orange";
    else if (A >= 570)
        cout << "Yellow";
    else if (A >= 495)
        cout << "Green";
    else if (A >= 450)
        cout << "Blue";
    else if (A >= 425)
        cout << "Indigo";
    else cout << "Violet";
}