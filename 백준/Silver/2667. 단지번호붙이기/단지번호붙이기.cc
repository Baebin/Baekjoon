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
vector<vector<int>> graph;
vector<vector<bool>> visit;

// Left, Right, Up, Down
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// Structure
struct Location {
    int x, y;
};

int BFS(Location loc) {
    queue<Location> que;
    que.push(loc);

    visit[loc.y][loc.x] = true;

    int cnt = 0;
    while (!que.empty()) {
        loc = que.front();
        que.pop();

        cnt++;
        for (int i = 0; i < 4; i++) {
            if (X < 0 || Y < 0 || X >= N || Y >= N)
                continue;
            if (graph[Y][X] && !visit[Y][X]) {
                que.push({ X, Y });
                visit[Y][X] = true;
            }
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    graph.resize(N, vector<int>(N));
    visit.resize(N, vector<bool>(N));

    string str;
    for (int y = 0; y < N; y++) {
        cin >> str;
        for (int x = 0; x < N; x++)
            graph[y][x] = str[x] == '1';
    }

    priority_queue<int, vector<int>, greater<int>> que;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (graph[y][x] && !visit[y][x])
                que.push(BFS({ x, y }));

    cout << que.size() << "\n";
    while (!que.empty()) {
        cout << que.top() << "\n";
        que.pop();
    }
}