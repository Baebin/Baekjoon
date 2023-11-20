#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int C;
        cin >> C;

        cout << (C / 25) << " "
            << ((C % 25) / 10) << " "
            << (((C % 25) % 10) / 5) << " "
            << (C % 5) << '\n';
    }
}