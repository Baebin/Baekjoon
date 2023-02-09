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

// Size
int N;

// Map
vector<vector<char>> graph;
vector<vector<bool>> visit;

// Left, Right, Up, Down
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// Wrong Check
bool d[2] = { false, true };

// Structure
struct Location {
    int x, y;
};

void resetVisit() {
    visit.assign(N, vector<bool>(N));
}

void BFS(Location loc, bool is_wrong) {
    queue<Location> que;
    que.push(loc);

    visit[loc.y][loc.x] = true;

    char color = graph[loc.y][loc.x];
    while (!que.empty()) {
        loc = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            if (X < 0 || Y < 0 || X >= N || Y >= N)
                continue;
            if (visit[Y][X])
                continue;
            if (color != graph[Y][X]) {
                if (!is_wrong) continue;
                if (color == 'B')
                    continue;
                if (graph[Y][X] == 'B')
                    continue;
            }
            que.push({ X, Y });
            visit[Y][X] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    graph.resize(N, vector<char>(N));

    string str;
    for (int y = 0; y < N; y++) {
        cin >> str;

        int len = str.length();
        for (int x = 0; x < len; x++)
            graph[y][x] = str[x];
    }

    for (int i = 0; i < 2; i++) {
        int cnt = 0;

        resetVisit();
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (!visit[y][x]) {
                    BFS({ x, y }, d[i]);
                    cnt++;
                }
            }
        }
        cout << cnt << " ";
    }
}