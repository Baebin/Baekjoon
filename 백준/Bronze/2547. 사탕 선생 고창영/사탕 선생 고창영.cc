#include <iostream>
using namespace  std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N;
        cin >> N;

        long long sum = 0, C;
        for (int i = 0; i < N; i++)
            cin >> C, sum = (sum + C) % N;
        if (sum % N == 0)
            cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}