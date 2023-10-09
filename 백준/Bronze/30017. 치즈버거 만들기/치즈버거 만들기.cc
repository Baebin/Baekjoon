#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    if (A >= B + 1)
        cout << (B * 2 + 1);
    else cout << (A * 2 - 1);
}