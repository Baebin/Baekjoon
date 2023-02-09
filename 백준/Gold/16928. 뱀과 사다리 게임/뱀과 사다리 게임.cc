#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Declare
#define MAX 100
#define X loc.x + i

// Map
vector<int> warp(MAX + 1);
vector<bool> visit(MAX + 1);

// Structure
struct Location {
    int x, cnt;
};

int BFS(Location loc) {
    queue<Location> que;
    que.push(loc);

    visit[loc.x] = true;

    while (!que.empty()) {
        loc = que.front();
        que.pop();

        if (loc.x == MAX)
            break;

        for (int i = 1; i <= 6; i++) {
            if (X < 1 || X > MAX)
                continue;

            int x = X;
            while (warp[x] > 0)
                x = warp[x];
            if (visit[x])
                continue;

            que.push({ x, loc.cnt + 1 });
            visit[x] = true;
        }
    }

    return loc.cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int x, y;
    for (int i = 0; i < N + M; i++) {
        cin >> x >> y;
        warp[x] = y;
    }

    cout << BFS({ 1, 0 });
}