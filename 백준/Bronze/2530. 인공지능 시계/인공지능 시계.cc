#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    
    int T = (A * 3600 + B * 60 + C) + D;
    cout << ((T / 3600) % 24) << " " << ((T / 60) % 60) << " " << (T % 60);
}