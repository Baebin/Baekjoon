#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int ans = 0;
    while (N--) {
        int H, W;
        cin >> H >> W;
        ans = max(ans, H * W);
    }
    cout << ans;
}