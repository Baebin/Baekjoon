#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string S;
    int X;

    int cnt = 0;
    bool reverse = false;
    while (N--) {
        cin >> S >> X;

        if (!reverse) {
            cnt++;
            if (cnt == 13)
                cnt = 1;
        }
        else {
            cnt--;
            if (cnt == 0)
                cnt = 12;
        }

        cout << cnt << " ";

        if (S == "HOURGLASS") {
            if (cnt != X)
                reverse = !reverse;
            cout << "NO\n";
            continue;
        }

        if (cnt == X)
            cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
}