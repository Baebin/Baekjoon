#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X loc.x + dx[i]
#define Y loc.y + dy[i]

int T;
int M, N, K;

vector<vector<bool>> visit;
vector<vector<bool>> graph_plant;

// Left, Right, Up, Down
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct Location {
    int x, y;
};

void BFS(Location loc) {
    queue<Location> que;

    que.push(loc);
    visit[loc.y][loc.x] = true;
    
    while (!que.empty()) {
        loc = que.front();
        que.pop();

        for (int i = 0; i < 4; i++) {
            if (X >= 0 && X < M && Y >= 0 && Y < N
                && !visit[Y][X] && graph_plant[Y][X]) {
                visit[Y][X] = true;
                que.push({ X, Y });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while (T--) {
        cin >> M >> N >> K;

        visit.assign(N, vector<bool>(M));
        graph_plant.assign(N, vector<bool>(M));

        int x, y;
        while (K--) {
            cin >> x >> y;
            graph_plant[y][x] = true;
        }

        int cnt = 0;
        for (x = 0; x < M; x++) {
            for (y = 0; y < N; y++) {
                if (!visit[y][x] && graph_plant[y][x]) {
                    BFS({ x, y });
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }
}