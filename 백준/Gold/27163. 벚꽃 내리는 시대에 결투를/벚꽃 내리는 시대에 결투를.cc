#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Declare
#define INF 2e9

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A, L;
    cin >> N >> A >> L;

    vector<vector<int>> dp(N + 1, vector<int>(L + 1, -INF));
    vector<vector<int>> route(N + 1, vector<int>(L + 1));
    dp[0][L] = A;

    vector<int> life_damage(N + 1);
    for (int turn = 1; turn <= N; turn++) {
        int X, Y;
        cin >> X >> Y;

        life_damage[turn] = Y;

        for (int life = 1; life <= L; life++) {
            // Validate
            if (dp[turn - 1][life] == -INF)
                continue;

            // X/-1
            if (Y == -1) {
                int value = max(dp[turn - 1][life] - X, 0);
                if (dp[turn][life] < value) {
                    dp[turn][life] = value;
                    route[turn][life] = 0;
                }
                continue;
            }

            // -1/Y
            if (X == -1) {
                if (life > Y) {
                    int value = dp[turn - 1][life];
                    if (dp[turn][life - Y] < value) {
                        dp[turn][life - Y] = value;
                        route[turn][life - Y] = Y;
                    }
                }
                continue;
            }

            // X/Y: Aura, Life
            if (dp[turn - 1][life] >= X) {
                int value = dp[turn - 1][life] - X;
                if (dp[turn][life] < value) {
                    dp[turn][life] = value;
                    route[turn][life] = 0;
                }
            }
            if (life > Y) {
                int value = dp[turn - 1][life];
                if (dp[turn][life - Y] < value) {
                    dp[turn][life - Y] = value;
                    route[turn][life - Y] = Y;
                }
            }
        }
    }

    // Validate
    for (int life = 1; life <= L; life++) {
        if (dp[N][life] != -INF) {
            // Result
            stack<char> st;

            // Tracking
            int tmp_life = life;
            for (int turn = N; turn >= 1; turn--) {
                int damage = route[turn][tmp_life];
                tmp_life += damage;

                if (damage == 0)
                    // Damage In Current Turn
                    if (life_damage[turn] == 0)
                        st.push('L');
                    else st.push('A');
                else st.push('L');
            }

            cout << "YES\n";
            while (!st.empty()) {
                cout << st.top();
                st.pop();
            }
            return 0;
        }
    }
    cout << "NO";
}