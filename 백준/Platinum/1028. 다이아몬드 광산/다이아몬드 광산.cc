#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// function
#define for_x() for (register int x = 0; x < C; x++)
#define for_y() for (register int y = 0; y < R; y++)

// Declare
#define LUP 0
#define RUP 1

// Row, Column
int R, C;

// Graph
queue<pair<int, int>> que;
vector<vector<bool>> diamond;

// L.UP: 0, R.UP: 1
vector<vector<vector<int>>> dp;

void init() {
    for_y() {
        for_x() {
            char c;
            cin >> c;

            diamond[y][x] = (c == '1');
            if (!diamond[y][x]) continue;
            que.push({ x, y });

            dp[y][x][LUP] = dp[y][x][RUP] = 1;
            if (y - 1 >= 0 && x - 1 >= 0)
                dp[y][x][LUP] = dp[y - 1][x - 1][LUP] + 1;
            if (y - 1 >= 0 && x + 1 < C)
                dp[y][x][RUP] = dp[y - 1][x + 1][RUP] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    // Init
    diamond.resize(R, vector<bool>(C));
    dp.resize(R, vector<vector<int>>(C, vector<int>(2)));

    // Input & DP
    init();

    // Count
    int cnt = 0;

    // Null Check
    if (!que.empty() && que.size() < 4) {
        cout << 1;
        return 0;
    }

    while (!que.empty()) {
        const int x = que.front().first;
        const int y = que.front().second;
        que.pop();

        // Length
        const int& LD = dp[y][x][LUP];
        const int& RD = dp[y][x][RUP];
        const int& LEN = min(LD, RD);

        // Debug
        // cout << LD << " " << RD << " " << LEN << endl;

        // Diamond Check
        for (register int len = LEN; len > cnt; len--) {
            const int Y = y - (len - 1);
            const int LX = x - (len - 1);
            const int RX = x + (len - 1);

            // Out of Range
            if (!(Y < R || LX >= 0 || RX < R)) continue;

            // Length Check
            if (dp[Y][LX][RUP] < len)
                continue;
            if (dp[Y][RX][LUP] < len)
                continue;

            // Update (Max)
            cnt = len;
            break;
        }
    }
    cout << cnt;
}