#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int ans = 0;
    int cnt = 0;
    while (N--) {
        int P;
        cin >> P;
        if (P)
            ans += (++cnt);
        else cnt = 0;
    }
    cout << ans;
}