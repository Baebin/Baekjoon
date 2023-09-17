#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    while (N--) {
        int H;
        cin >> H;
        
        while (H--)
            cout << "=";
        cout << "\n";
    }
}