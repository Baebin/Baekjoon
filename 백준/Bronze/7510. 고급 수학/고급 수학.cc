#include <iostream>
using namespace std;

int main(void){
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        
        if (A * A == B * B + C * C)
            cout << "Scenario #" << i << ": " << '\n' << "yes" << "\n\n";
        else if (B * B == A * A + C * C)
            cout << "Scenario #" << i << ": " << '\n' << "yes" << "\n\n";
        else if (C * C == A * A + B * B)
            cout << "Scenario #" << i << ": " << '\n' << "yes" << "\n\n";
        else cout << "Scenario #" << i << ": " << '\n' << "no" << "\n\n";
    }
}