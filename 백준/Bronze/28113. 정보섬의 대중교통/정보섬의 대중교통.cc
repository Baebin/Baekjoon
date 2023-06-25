#include <iostream>
using namespace std;

int main() {
    long long N, A, B;
    cin >> N >> A >> B;
    
    B -= N;
    if (B > 0)
        N += B;
    if (A < N)
        cout << "Bus";
    else if (A > N)
        cout << "Subway";
    else
        cout << "Anything";
}