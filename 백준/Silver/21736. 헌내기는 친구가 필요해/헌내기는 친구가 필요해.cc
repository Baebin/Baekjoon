#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <queue>
using namespace std;

#define EMPTY 'O'
#define DOYEON 'I'
#define PERSON 'P'

// Structure
struct Location {
    int x, y;
};

// Row, Column
int N, M;

// Graph
vector<string> campus;

// Doyeon
Location p;

// BFS
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

int BFS() {
    int cnt = 0;

    queue<Location> que;
    que.push(p);

    vector<vector<bool>> visit(N, vector<bool>(M));
    while (!que.empty()) {
        Location cur = que.front();
        que.pop();

        for (register int i = 0; i < 4; i++) {
            Location next = Location{ cur.x + dx[i], cur.y + dy[i] };
            // Out of Range
            if (next.x < 0 || next.y < 0 || next.x >= M || next.y >= N)
                continue;
            // Visit Check
            if (visit[next.y][next.x])
                continue;
            // Path Check
            if (campus[next.y][next.x] != EMPTY && campus[next.y][next.x] != PERSON)
                continue;
            if (campus[next.y][next.x] == PERSON)
                cnt++;
            visit[next.y][next.x] = true;
            que.push(next);
        }
    }
    return cnt;
}

void input() {
    cin >> N >> M;
    campus.resize(N);
    for (register int i = 0; i < N; i++) {
        cin >> campus[i];
        for (register int j = 0; j < M; j++)
            if (campus[i][j] == DOYEON)
                p = Location{ j, i };
    }
}

// Simulation Result
int cnt;
void simulation() {
    cnt = BFS();
}

void output() {
    // Exception: (if cnt == 0 ? "TT" : cnt)
    if (cnt == 0) cout << "TT";
    else cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    simulation();
    output();
}