#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int s = 0, m = 100;
        for (register int i = 0; i < 7; i++) {
            int N;
            cin >> N;
            if (N % 2)
                continue;
            m = min(m, N);
            s += N;
        }
        cout << s << " " << m << '\n';
    }
}