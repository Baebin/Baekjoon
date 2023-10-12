#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    if ((A <= B && B <= C) || (C <= B && B <= A))
        cout << B;
    else if ((A <= C && C <= B) || (B <= C && C <= A))
        cout << C;
    else cout << A;
}