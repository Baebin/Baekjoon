#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    int X = abs((A - 1)/4 - (B - 1)/4);
    int Y = abs((A - 1)%4 - (B - 1)%4);
    cout << (X + Y);
}