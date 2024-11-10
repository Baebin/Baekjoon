#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// RIGHT, DOWN, LEFT, UP
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<vector<bool>> visit(M, vector<bool>(N));

    int x = 0, y = 0, dr = 0, cnt = (M * N), ans = 0;
    while (true) {
        if (!visit[y][x]) {
            visit[y][x] = true;
            if (--cnt <= 0) break;
        }
        
        int nx = x + dx[dr];
        int ny = y + dy[dr];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M || visit[ny][nx]) {
            dr = (++dr) % 4;
            ans++;
        } else x = nx, y = ny;
    }
    cout << (ans) << '\n';
}