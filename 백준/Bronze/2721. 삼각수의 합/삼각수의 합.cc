#include <iostream>
using namespace std;
 
int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        int ans = 0;
        for (int i = 1; i <= N; i++)
            ans += i * ((i + 1) * (i + 2) / 2);
        cout << ans << '\n';
    }
}
