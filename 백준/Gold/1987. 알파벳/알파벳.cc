#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Declare
#define ALPHABET_MAX 26
#define X loc.x + dx[i]
#define Y loc.y + dy[i]

// Left, Right, Up, Down
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

// Row, Column
int R, C;

// Graph
vector<string> graph;

// Strucure
struct Location {
    int x, y;

    // Validate
    bool isInRange() {
        return !(x < 0 || y < 0 || x >= C || y >= R);
    }
};

// DFS Variables
int depth_max = 0;
vector<bool> canMove(ALPHABET_MAX, true);

void DFS(const Location& loc, const int& depth) {
    depth_max = max(depth_max, depth);

    for (int i = 0; i < 4; i++) {
        Location tmpLoc = { X, Y };
        if (!tmpLoc.isInRange())
            continue;
        if (!canMove[graph[Y][X]])
            continue;

        // Backtracking
        canMove[graph[Y][X]] = false;
        DFS(tmpLoc, depth + 1);
        canMove[graph[Y][X]] = true;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;
    graph.resize(R);

    for (int i = 0; i < R; i++) {
        cin >> graph[i];
        for (int j = 0; j < C; j++)
            graph[i][j] -= 'A';
    }

    // Start Point
    canMove[graph[0][0]] = false;

    DFS({ 0, 0 }, 1);
    cout << depth_max;
}