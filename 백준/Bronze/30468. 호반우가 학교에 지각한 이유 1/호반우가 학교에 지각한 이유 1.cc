#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int STR, DEX, INT, LUK, N;
    cin >> STR >> DEX >> INT >> LUK >> N;

    int ans = (N * 4) - (STR + DEX + INT + LUK);
    if (ans < 0)
        ans = 0;
    cout << ans;
}