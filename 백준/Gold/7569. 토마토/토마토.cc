#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X loc.x + dx[i]
#define Y loc.y + dy[i]
#define Z loc.z + dz[i]

// x, y, z
int N, M, H;

// Tomato Map
vector<vector<vector<int>>> graph;

// Left, Right, UP, Down, ZUP, ZDown
int dx[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, -1, 1 };

struct Location {
    int x, y, z;
};

// BFS
queue<Location> que;
vector<vector<vector<int>>> days;
vector<vector<vector<bool>>> visit;

void BFS() {
    Location loc;

    while (!que.empty()) {
        loc = que.front();
        que.pop();

        for (int i = 0; i < 6; i++) {
            if (min(X, min(Y, Z)) < 0)
                continue;
            if (X >= N || Y >= M || Z >= H)
                continue;
            if (visit[Z][Y][X] || graph[Z][Y][X] != 0)
                continue;
            que.push({ X, Y, Z });
            visit[Z][Y][X] = true;

            days[Z][Y][X] = days[loc.z][loc.y][loc.x] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;

    days.resize(H, vector<vector<int>>(M, vector<int>(N)));
    graph.resize(H, vector<vector<int>>(M, vector<int>(N)));
    visit.resize(H, vector<vector<bool>>(M, vector<bool>(N)));

    for (int z = 0; z < H; z++) {
        for (int y = 0; y < M; y++) {
            for (int x = 0; x < N; x++) {
                cin >> graph[z][y][x];
                if (graph[z][y][x] == 1)
                    que.push({ x, y, z });
            }
        }
    }

    if (que.size() == H * M * N) {
        cout << 0;
        return 0;
    }
    BFS();

    int day = 0;
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < M; y++) {
            for (int x = 0; x < N; x++) {
                // 고립된 Mr. Tomamo
                if (!visit[z][y][x] && graph[z][y][x] == 0) {
                    cout << -1;
                    return 0;
                }

                // 마지막에 익은 Mrs. Tomato
                if (days[z][y][x] > day)
                    day = days[z][y][x];
            }
        }
    }

    cout << day;
}