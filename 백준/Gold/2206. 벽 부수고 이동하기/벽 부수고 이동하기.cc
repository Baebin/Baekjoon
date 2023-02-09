#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Declare
#define X loc.x + dx[i]
#define Y loc.y + dy[i]

// Row, Column
int N, M;

// Map
vector<string> graph;
vector<vector<vector<bool>>> visit;

// Left, Right, Up, Down
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

struct Location {
    int x, y, cnt, can_break;

    bool compare(const Location& a) {
        return (x + 1 == a.x && y + 1 == a.y);
    }
};

int BFS(Location loc) {
    queue<Location> que;
    que.push(loc);

    visit[loc.y][loc.x][true] = true;

    while (!que.empty()) {
        loc = que.front();
        que.pop();

        // Find
        if (loc.compare({ M, N }))
            return loc.cnt;

        // Route Search
        for (int i = 0; i < 4; i++) {
            // Out of Range
            if (X < 0 || X >= M || Y < 0 || Y >= N)
                continue;
            // Past Path
            if (visit[Y][X][loc.can_break])
                continue;

            // Check The Wall
            if (graph[Y][X] == '1') {
                // Can't break The Wall
                if (!loc.can_break)
                    continue;
                visit[Y][X][false] = true;
                que.push({ X, Y, loc.cnt + 1, false });
                continue;
            }
            visit[Y][X][loc.can_break] = true;
            que.push({ X, Y, loc.cnt + 1, loc.can_break });
        }
    }

    // Can't find
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    graph.resize(N);
    visit.resize(N, vector<vector<bool>>(M, vector<bool>(2)));

    for (int i = 0; i < N; i++) {
        string map;
        cin >> graph[i];
    }

    // Location: (0, 0), Count: 1, Can Break: true
    cout << BFS({ 0, 0, 1, true });
}