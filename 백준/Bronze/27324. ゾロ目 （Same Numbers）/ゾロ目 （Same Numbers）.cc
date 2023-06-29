#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    if (N % 10 == N / 10)
        cout << 1;
    else cout << 0;
}