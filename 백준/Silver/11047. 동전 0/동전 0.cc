#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> coin(N);
    for (int i = 0; i < N; i++)
        cin >> coin[i];

    int cnt = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (K >= coin[i]) {
            cnt += K / coin[i];
            K %= coin[i];
        }
        if (K == 0) break;
    }

    cout << cnt;
}