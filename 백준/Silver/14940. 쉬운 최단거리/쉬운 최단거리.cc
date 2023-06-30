#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Location { int x, y; };
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

void BFS(const Location& LOC, vector<vector<int>>& graph, vector<vector<int>>& dist, const int& N, const int& M) {
    queue<Location> que;
    que.push(LOC);

    while (!que.empty()) {
        Location loc = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            Location next = Location{ loc.x + dx[i], loc.y + dy[i] };
            if (next.x < 0 || next.y < 0 || next.x >= M || next.y >= N) continue;
            if (graph[next.y][next.x] != 1) continue;
            if (dist[next.y][next.x]) continue;
            dist[next.y][next.x] = dist[loc.y][loc.x] + 1;
            que.push(next);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j == LOC.x && i == LOC.y) cout << 0 << " ";
            else if (dist[i][j] == 0) cout << (graph[i][j] == 0) - 1 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(M));
    vector<vector<int>> dist(N, vector<int>(M));

    Location loc;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if (graph[i][j] != 2) continue;
            loc = { j, i };
        }
    }
    BFS(loc, graph, dist, N, M);
}