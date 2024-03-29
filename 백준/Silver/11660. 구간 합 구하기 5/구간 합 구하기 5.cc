#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> sum(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int num;
            cin >> num;

            // ~(x, y) = UP + Left + This = ~UP + (~Left - ~UP&LEFT) + This
            sum[i][j] = sum[i - 1][j] + (sum[i][j - 1] - sum[i - 1][j - 1]) + num;
        }
    }

    while (M--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // (x1, y1) ~ (x2, y2) = ~(x2, y2) - ~(x2, y1 - 1) - ~(x1 - 1, y2) + ~(x1 - 1, y1 - 1)
        cout << sum[x2][y2] - (sum[x2][y1 - 1] + sum[x1 - 1][y2] - (sum[x1 - 1][y1 - 1])) << "\n";
    }
}