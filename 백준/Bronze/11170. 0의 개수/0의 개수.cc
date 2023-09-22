#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        int cnt = 0;
        for (int i = N; i <= M; i++) {
            string num = to_string(i);
            for (const char& c : num)
                if (c == '0') cnt++;
        }
        cout << cnt << '\n';
    }
}