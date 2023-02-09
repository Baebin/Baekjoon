#include <iostream>
#include <vector>
using namespace std;

vector<int> vec(1000001);

int dp(int x) {
    if (x <= 3) return x / 2;
    if (vec[x] > 0) return vec[x];

    int cnt = 1 + dp(x - 1);
    if (x % 3 == 0) cnt = min(cnt, 1 + dp(x / 3));
    if (x % 2 == 0) cnt = min(cnt, 1 + dp(x / 2));

    vec[x] = cnt;
    return cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X;
    cin >> X;

    cout << dp(X);
}