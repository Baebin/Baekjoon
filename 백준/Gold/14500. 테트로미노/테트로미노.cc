#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define X loc.x + dx[i]
#define Y loc.y + dy[i]

// Row, Column
int N, M;

// Map
vector<vector<int>> graph;
vector<vector<bool>> visit;

// Left, Right, Up, Down
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 0 };

struct Location {
    int x, y, cnt;
};

int DFS(Location loc) {
    // Depth Limit
    if (loc.cnt == 4)
        return graph[loc.y][loc.x];
    int sum = 0;

    for (int i = 0; i < 4; i++) {
        if (X < 0 || Y < 0 || X >= M || Y >= N)
            continue;
        if (visit[Y][X])
            continue;
        visit[Y][X] = true;
        sum = max(sum, graph[loc.y][loc.x] + DFS({ X, Y, loc.cnt + 1 }));
        visit[Y][X] = false;
    }

    if (loc.cnt == 1) {
        // ㅗ, ㅜ
        if (loc.x + 2 < M && loc.y + 1 < N) {
            sum = max(sum,
                graph[loc.y][loc.x + 1] + graph[loc.y + 1][loc.x]
                + graph[loc.y + 1][loc.x + 1] + graph[loc.y + 1][loc.x + 2]);
            sum = max(sum,
                graph[loc.y][loc.x] + graph[loc.y][loc.x + 1]
                + graph[loc.y][loc.x + 2] + graph[loc.y + 1][loc.x + 1]);
        }
        // ㅏ, ㅓ
        if (loc.x + 1 < M && loc.y + 2 < N) {
            sum = max(sum,
                graph[loc.y][loc.x] + graph[loc.y + 1][loc.x]
                + graph[loc.y + 1][loc.x + 1] + graph[loc.y + 2][loc.x]);
            sum = max(sum,
                graph[loc.y][loc.x + 1] + graph[loc.y + 1][loc.x]
                + graph[loc.y + 1][loc.x + 1] + graph[loc.y + 2][loc.x + 1]);
        }
    }

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    graph.resize(N, vector<int>(M));
    visit.resize(N, vector<bool>(M));

    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            cin >> graph[y][x];

    int sum = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            visit[y][x] = true;
            sum = max(sum, DFS({ x, y, 1 }));
            visit[y][x] = false;
        }
    }
    cout << sum;
}