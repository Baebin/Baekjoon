#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int ans = 0;
    while (N--) {
        int F;
        cin >> F;
        ans += (F - 1);
    }
    cout << (ans += 1);
}