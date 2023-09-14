#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    int cnt = 0;

    int A, B;

    for (register int i = 0; i < 10; i++) {
        cin >> A >> B;
        cnt = max(cnt, ans += B - A);
    }
    cout << cnt;
}