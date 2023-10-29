#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    int sum = 0;
    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;
        
        // A, B, C
        if (A == B && B == C)
            sum = max(sum, 10000 + A * 1000);
        // A, B
        else if (A == B && B != C)
            sum = max(sum, 1000 + A * 100);
        // B, C
        else if (A != B && B == C)
            sum = max(sum, 1000 + B * 100);
        // A, C
        else if (A == C && A != B)
            sum = max(sum, 1000 + C * 100);
        else sum = max(sum, max(A, max(B, C)) * 100);
    }
    cout << sum;
}