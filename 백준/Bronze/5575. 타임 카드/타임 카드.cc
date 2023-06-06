#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 3; i++) {
        int A, B, C, D, E, F;
        cin >> A >> B >> C >> D >> E >> F;

        int H = C + B * 60 + A * 60 * 60;
        H = (F + E * 60 + D * 60 * 60) - H;
        cout << (H / 3600) << " " << (H / 60) % 60 << " " << H % 60 << "\n";
    }
}