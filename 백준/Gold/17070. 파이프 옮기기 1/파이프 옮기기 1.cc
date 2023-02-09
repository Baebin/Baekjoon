#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define DIAGONAL 2
#define STRAIGHT 0
#define DOWN_STRAIGHT 1

// Row, Column
int N;

// Graph
vector<vector<int>> graph;
vector<vector<bool>> visit;

// Strucutre
struct Location {
    int x, y;
    int status;

    bool isStraight() {
        return (status == STRAIGHT);
    }
    bool isDownStraight() {
        return (status == DOWN_STRAIGHT);
    }
    bool isInRange() {
        if (x < 0 || y < 0 || x >= N || y >= N)
            return false;
        if (graph[y][x])
            return false;
        return !(visit[y][x]);
    }
};

int cnt = 0;
void DFS(Location loc) {
    // Count
    if (loc.x + 1 == N && loc.y + 1 == N) {
        cnt++;
        return;
    }

    // Init
    Location down = { loc.x, loc.y + 1, DOWN_STRAIGHT };
    Location right = { loc.x + 1, loc.y, STRAIGHT };
    Location right_down = { loc.x + 1, loc.y + 1, DIAGONAL };

    // Right
    if (right.isInRange()) {
        if (!loc.isDownStraight()) {
            visit[right.y][right.x] = true;
            DFS(right);
            visit[right.y][right.x] = false;
        }

        // Right Down
        if (down.isInRange() && right_down.isInRange()) {
            visit[right.y][right.x] = true;
            visit[down.y][down.x] = true;
            visit[right_down.y][right_down.x] = true;

            DFS(right_down);

            visit[right.y][right.x] = false;
            visit[down.y][down.x] = false;
            visit[right_down.y][right_down.x] = false;
        }
    }

    // Down
    if (!loc.isStraight() && down.isInRange()) {
        visit[down.y][down.x] = true;
        DFS(down);
        visit[down.y][down.x] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    graph.resize(N, vector<int>(N));
    visit.resize(N, vector<bool>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    // Start Point: (0, 1)
    visit[0][0] = true;
    visit[0][1] = true;

    DFS({ 1, 0, STRAIGHT });
    cout << cnt;
}