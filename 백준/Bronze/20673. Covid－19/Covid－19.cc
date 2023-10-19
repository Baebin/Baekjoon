#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    if (A <= 50 && B <= 10)
        cout << "White";
    else if (B > 30)
        cout << "Red";
    else cout << "Yellow";
}