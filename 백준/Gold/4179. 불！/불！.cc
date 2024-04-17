#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define WALL '#'
#define EMPTY '.'
#define JIHOON 'J'
#define FIRE 'F'

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct Location {
    int x, y, cost;
    bool isOutOfRange(const int& R, const int& C) {
        return (x < 0 || y < 0 || x >= C || y >= R);
    }
    bool isInOutSide(const int& R, const int& C) {
        return (x == 0 || x == C - 1 || y == 0 || y == R - 1);
    }
};

int bfs(const int& R, const int& C, const vector<string>& graph, const vector<Location>& fires, Location loc) {
    queue<Location> que;

    vector<vector<vector<bool>>> visit(R, vector<vector<bool>>(C, vector<bool>(2)));
    visit[loc.y][loc.x][0] = true;

    for (Location fire : fires) {
        visit[fire.y][fire.x][1] = true;
        que.push(fire);
    }
    que.push(loc);
    while (!que.empty()) {
        loc = que.front();
        que.pop();

        if (!visit[loc.y][loc.x][1] && loc.isInOutSide(R, C))
            return loc.cost;
        for (int d = 0; d < 4; d++) {
            Location next = Location{ loc.x + dx[d], loc.y + dy[d], loc.cost + 1 };
            if (next.isOutOfRange(R, C))
                continue;
            if (graph[next.y][next.x] != EMPTY)
                continue;
            bool isFire = visit[loc.y][loc.x][1];
            if (visit[next.y][next.x][1] == true)
                continue;
            if (visit[next.y][next.x][0])
                continue;
            visit[next.y][next.x][isFire] = true;
            que.push(next);
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int R, C;
    cin >> R >> C;

    Location jihoon{ -1, -1, 0 };
    vector<string> graph(R);

    vector<Location> fires;
    for (int i = 0; i < R; i++) {
        cin >> graph[i];
        for (int j = 0; j < C; j++) {
            Location loc = Location{ j, i, 1 };
            if (graph[i][j] == JIHOON)
                jihoon = loc;
            if (graph[i][j] == FIRE)
                fires.emplace_back(loc);
        }
    }
    int ans = bfs(R, C, graph, fires, jihoon);
    if (ans < 0)
        cout << "IMPOSSIBLE" << '\n';
    else cout << ans << '\n';
}

