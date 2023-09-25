#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    int A = a * 3 + b * 2 + c;
    cin >> a >> b >> c;
    
    int B = a * 3 + b * 2 + c;
    
    if (A == B)
        cout << "T";
    else if (A > B)
        cout << "A";
    else cout << "B";
}