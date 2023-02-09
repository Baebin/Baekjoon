#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Declear
#define X loc.x + dx[i]
#define Y loc.y + dy[i]

// Left, Right, DownLeft, DownRight
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// Row, Column
int N, M;

// Graph
vector<vector<int>> maze;

// Structure
struct Location {
    int x, y, cnt;

    bool compare(const Location& loc) {
        return (x == loc.x) && (y == loc.y);
    }
};

int BFS(Location loc) {
    vector<vector<int>> visit(N, vector<int>(M));
    visit[loc.y][loc.x] = true;

    queue<Location> que;
    que.push(loc);

    while (!que.empty()) {
        loc = que.front();
        que.pop();

        if (loc.compare({ M - 1, N - 1 }))
            break;

        for (int i = 0; i < 4; i++) {
            if (X < 0 || Y < 0 || Y >= N || X >= M)
                continue;
            if (!visit[Y][X] && maze[Y][X]) {
                que.push({ X, Y, loc.cnt + 1 });
                visit[Y][X] = true;
            }
        }
    }

    return loc.cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    maze.resize(N, vector<int>(M));

    string map;
    for (int y = 0; y < N; y++) {
        cin >> map;

        for (int x = 0; x < M; x++)
            maze[y][x] = map[x] == '1';
    }

    cout << BFS({ 0, 0, 1 });
}