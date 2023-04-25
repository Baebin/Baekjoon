#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Declare
#define EMPTY -1
#define CHEESE 1

// Left, Right, Up, Down
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

// Row, Column
int N, M;

// Cheese
vector<vector<int>> cheese;

struct Location {
    int x, y;

    bool isInRange() {
        return (x >= 0 && y >= 0 && x < M && y < N);
    }
};

void separateAir() {
    queue<Location> que;
    vector<vector<bool>> visit(N, vector<bool>(M));

    visit[0][0] = true;
    que.push(Location{ 0, 0 });
    while (!que.empty()) {
        Location loc = que.front();
        que.pop();

        for (int d = 0; d < 4; d++) {
            Location next = Location{ loc.x + dx[d], loc.y + dy[d] };
            if (!next.isInRange()) continue;
            if (visit[next.y][next.x]) continue;
            if (cheese[next.y][next.x] == CHEESE) continue;

            que.push(next);
            visit[next.y][next.x] = true;
            cheese[next.y][next.x] = EMPTY;
        }
    }
}

void meltCheese(int& cheese_sum) {
    separateAir();

    queue<Location> que;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (cheese[y][x] != CHEESE) continue;

            int sum = 0;
            for (int d = 0; d < 4; d++) {
                Location next = Location{ x + dx[d], y + dy[d] };
                if (!next.isInRange()) continue;
                sum += (cheese[next.y][next.x] == EMPTY);
            }
            if (sum >= 2) {
                que.push(Location{ x, y });
                if ((--cheese_sum) == 0) return;
            };
        }
    }

    while (!que.empty()) {
        Location loc = que.front();
        que.pop();

        cheese[loc.y][loc.x] = EMPTY;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cheese.resize(N, vector<int>(M));

    int sum = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> cheese[y][x];
            if (cheese[y][x]) sum++;
        }
    }

    int time = 0;
    while (sum) {
        time++;

        separateAir();
        meltCheese(sum);
    }
    cout << time;
}