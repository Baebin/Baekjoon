#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    int sum = A + B + C;
    if (A + B + C >= 100)
        cout << "OK";
    else if (A <= B && A <= C)
        cout << "Soongsil";
    else if (B <= A && B <= C)
        cout << "Korea";
    else cout << "Hanyang";
}