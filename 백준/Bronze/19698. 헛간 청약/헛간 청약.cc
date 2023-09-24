#include <iostream>
using namespace std;

int main() {
    int N, W, H, L;
    cin >> N >> W >> H >> L;
    
    int cnt = (W / L) * (H / L);
    cout << min(N, cnt);
}