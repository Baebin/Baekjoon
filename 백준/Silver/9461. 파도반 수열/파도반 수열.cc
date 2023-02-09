#include <iostream>
#include <vector>
using namespace std;

#define MAX 100

vector<long long> P(MAX + 1);

long long dp(const int& N) {
    // 1, 1, 1, 2, 2, 3, 4, 5, 7, 9

    for (int i = 4; i <= N; i++) {
        if (P[i] > 0) continue;
        P[i] = P[i - 2] + P[i - 3];
    }

    return P[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    P[1] = 1;
    P[2] = 1;
    P[3] = 1;

    int N;
    while (T--) {
        cin >> N;
        cout << dp(N) << "\n";
    }
}