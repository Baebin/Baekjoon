#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declear
#define X loc.x + d[j] * len / 3
#define Y loc.y + d[i] * len / 3

// Search 3 * 3
int d[3] = { 0, 1, 2 };

int N;
int cnt[3] = { 0, 0, 0 };

// Graph
vector<vector<int>> graph;

struct Location {
    int x, y;
};

void divive(Location loc, const int& len) {
    int color = graph[loc.y][loc.x];

    for (int y = loc.y; y < loc.y + len; y++) {
        for (int x = loc.x; x < loc.x + len; x++) {
            if (color != graph[y][x]) {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (X < 0 || Y < 0 || X >= N || Y >= N)
                            continue;
                        divive({ X, Y }, len / 3);
                    }
                }
                return;
            }
        }
    }

    cnt[color + 1]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    graph.resize(N, vector<int>(N));

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> graph[y][x];
    divive({ 0, 0 }, N);

    for (int count : cnt)
        cout << count << "\n";
}