#include <iostream>
using namespace std;

int main() {
    int A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    
    cout << (min(min(A, B), C) + min(D, E) - 50);
}