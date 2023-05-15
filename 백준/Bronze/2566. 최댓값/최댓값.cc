#include <iostream>
using namespace std;

int main() {
    int r, c;
    int max = -1;
    for (int y = 1; y <= 9; y++) {
        for (int x = 1; x <= 9; x++) {
            int num;
            cin >> num;
            
            if (max < num) {
                max = num;
                r = y, c = x;
            }
        }
    }
    cout << max << "\n";
    cout << r << " " << c;
}