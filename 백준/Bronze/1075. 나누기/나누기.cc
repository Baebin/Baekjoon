#include <iostream>
using namespace std;

// Structure
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, F;
    cin >> N >> F;

    const int& remain = (N % F);
    int ans = (N % 100 - remain) + F;
    while (ans >= F)
        ans -= F;
    if (ans < 10)
        cout << 0;
    cout << ans;
}