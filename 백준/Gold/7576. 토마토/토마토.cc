#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X loc.x + dx[i]
#define Y loc.y + dy[i]

// x, y
int N, M;

// Tomato Map
vector<vector<int>> graph;

// Left, Right, UP, Down
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct Location {
    int x, y;
};

// BFS
queue<Location> que;
vector<vector<int>> days;
vector<vector<bool>> visit;

void BFS() {
    Location loc;

    while (!que.empty()) {
        loc = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            if (X >= 0 && Y >= 0 && X < N && Y < M
                && !visit[Y][X] && graph[Y][X] == 0) {
                que.push({ X, Y });
                visit[Y][X] = true;

                days[Y][X] = days[loc.y][loc.x] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    days.resize(M, vector<int>(N));
    graph.resize(M, vector<int>(N));
    visit.resize(M, vector<bool>(N));

    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            cin >> graph[y][x];
            if (graph[y][x] == 1)
                que.push({ x, y });
        }
    }

    if (que.size() == M * N) {
        cout << 0;
        return 0;
    }
    BFS();

    int day = 0;
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            // 고립된 Mr. Tomamo
            if (!visit[y][x] && graph[y][x] == 0) {
                cout << -1;
                return 0;
            }

            // 마지막에 익은 Mrs. Tomato
            if (days[y][x] > day)
                day = days[y][x];
        }
    }

    cout << day;
}