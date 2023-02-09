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

// Left, Right, Up, Down
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

// Row, Column
int N, M;

// Graph
vector<vector<int>> graph;

// Structure
struct Location {
    int x, y;
};

// DFS Combination
int combination_size;
vector<Location> combination;

int BFS() {
    // Copy
    vector<vector<int>> graph_tmp = graph;

    // Virus
    int cnt = 0;
    queue<Location> que;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (graph[i][j] == 2)
                que.push({ j, i });
            else if (graph[i][j] == 0)
                cnt++;

    Location loc;
    while (!que.empty()) {
        loc = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            if (X < 0 | Y < 0 | X >= M | Y >= N)
                continue;
            if (graph_tmp[Y][X] != 0)
                continue;
            que.push({ X, Y });
            graph_tmp[Y][X] = 2;

            // Count
            cnt--;
        }
    }
    return cnt;
}

int cnt = 0;
void DFS(const int& x, const int& depth) {
    if (depth == 3) {
        cnt = max(cnt, BFS());
        return;
    }
    Location loc;
    for (int i = x + 1; i < combination_size; i++) {
        loc = combination[i];
        graph[loc.y][loc.x] = 1;
        DFS(i, depth + 1);
        graph[loc.y][loc.x] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    graph.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 0)
                combination.push_back({ j, i });
        }
    }
    combination_size = combination.size();

    DFS(-1, 0);
    cout << cnt;
}