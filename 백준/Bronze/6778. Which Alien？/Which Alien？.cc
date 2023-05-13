#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    
    if (A >= 3 && B <= 4)
        cout << "TroyMartian" << "\n";
    if (A <= 6 && B >= 2)
        cout << "VladSaturnian" << "\n";
    if (A <= 2 && B <= 3)
        cout << "GraemeMercurian" << "\n";
}