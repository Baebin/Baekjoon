#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2e9

int N, r1, c1, r2, c2;
vector<vector<int>> cnt;

int dx[6] = {-1, 1, -2 , 2, -1, 1 };
int dy[6] = {-2, -2, 0 , 0, 2, 2 };

struct Location {
    int x, y, cnt;
};

void bfs() {
    queue<Location> que;
    que.push(Location { c1, r1, 0 });
    cnt[r1][c1] = 0;

    while (!que.empty()) {
        Location cur = que.front();
        que.pop();

        for (register int i = 0; i < 6; i++) {
            Location next = Location{ cur.x + dx[i], cur.y + dy[i], cur.cnt + 1 };
            if (next.x < 0 || next.y < 0 || next.x >= N || next.y >= N) continue;
            if (cnt[next.y][next.x] != INF) continue;
            cnt[next.y][next.x] = next.cnt;
            que.push(next);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r1 >> c1 >> r2 >> c2;
    cnt.resize(N , vector<int>(N, INF));

    bfs();
    if (cnt[r2][c2] == INF) cout << -1;
    else cout << cnt[r2][c2];
}