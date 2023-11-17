#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        int S = 0;
        while (N--) {
            int A;
            cin >> A;
            S += A;
        }
        cout << S << "\n";
    }
}