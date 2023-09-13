#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    int cnt = 0;

    int A, B;

    // 1번역
    cin >> A >> B;
    cnt = max(cnt, ans += B);

    // 2번역
    cin >> A >> B;
    cnt = max(cnt, ans += B - A);

    // 3번역
    cin >> A >> B;
    cnt = max(cnt, ans += B - A);

    // 4번역
    cin >> A >> B;
    cnt = max(cnt, ans += B - A);

    cout << cnt;
}