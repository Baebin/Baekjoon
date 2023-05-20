#include <iostream>
using namespace std;

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;
    
    int S = min(A, N) + min(B, N) + min(C, N);
    cout << S;
}