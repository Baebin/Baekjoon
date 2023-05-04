#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define forx() for (register int x = 1; x <= C; x++)
#define fory() for (register int y = 1; y <= R; y++)

// Left, Right, Up, Down
const int dx[4] = { -1, 1, 0, 0 };
const int dy[4] = { 0, 0, -1, 1 };

class Dust {
public:
    int x, y;
    int stack;
};

class DustSimulator {
public:
    explicit DustSimulator(const int& r, const int& c, const int& t) : R(r), C(c), T(t) {
        graph.resize(R + 1, vector<int>(C + 1));
        this->cin();
    }
    int run() {
        // Queue
        fory() forx()
            if (graph[y][x] > 0)
                que.push(Dust{ x, y, graph[y][x] });

        // BFS
        while (!que.empty()) {
            Dust dust = que.front();
            que.pop();

            int cnts = 0;
            int amount = dust.stack / 5;
            for (register int d = 0; d < 4; d++) {
                int x = dust.x + dx[d], y = dust.y + dy[d];
                if (x < 1 || y < 1 || x > C || y > R) continue;
                if (graph[y][x] == -1) continue;
                graph[y][x] += amount;
                cnts++;
            }
            graph[dust.y][dust.x] -= amount * cnts;
        }
        filter(graph);

        // Recursion
        if (--T)
            return run();

        int dusts = 0;
        fory() forx()
            if (graph[y][x] > 0)
                dusts += graph[y][x];
        return dusts;
    }
protected:
    void cin() {
        fory() {
            forx() {
                std::cin >> graph[y][x];

                // Air Filter
                if (graph[y][x] != -1)
                    continue;
                if (UP) DOWN = y;
                else UP = y;
            }
        }
    }
    void filter(vector<vector<int>>& dust) {
        // Top, Bottom
        for (register int y = UP - 2; y >= 1; y--)
            dust[y + 1][1] = dust[y][1];
        for (register int y = DOWN + 2; y <= R; y++)
            dust[y - 1][1] = dust[y][1];
        // Mid
        for (register int x = 2; x <= C; x++) {
            dust[1][x - 1] = dust[1][x];
            dust[R][x - 1] = dust[R][x];
        }
        // Left
        for (register int y = 2; y <= UP; y++)
            dust[y - 1][C] = dust[y][C];
        for (register int y = R - 1; y >= DOWN; y--)
            dust[y + 1][C] = dust[y][C];
        // Right
        for (register int x = C - 1; x >= 2; x--) {
            dust[UP][x + 1] = dust[UP][x];
            dust[DOWN][x + 1] = dust[DOWN][x];
        }
        // Dust Filter - Clear
        dust[UP][2] = dust[DOWN][2] = 0;
    }
private:
    int R, C, T;
    int UP, DOWN;

    queue<Dust> que;
    vector<vector<int>> graph;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C, T;
    cin >> R >> C >> T;

    DustSimulator simulator(R, C, T);
    cout << simulator.run();
}