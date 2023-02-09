#include <iostream>
#include <vector>
using namespace std;

#define X x + (dx[k] * (len / 2))
#define Y y + (dy[k] * (len / 2))
#define COLOR graph[y][x]

vector<vector<int>> graph;

// White, Black
int cnt[2] = { 0, 0 };

// Left, Right, DownLeft, DownRight
int dx[4] = { 0, 1, 0, 1 };
int dy[4] = { 0, 0, 1, 1 };

void checkPiece(int x, int y, int len) {
    for (int i = y; i < y + len; i++) {
        for (int j = x; j < x + len; j++) {
            if (COLOR != graph[i][j]) {
                for (int k = 0; k < 4; k++)
                    checkPiece(X, Y, len / 2);
                return;
            }
        }
    }

    cnt[COLOR]++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    graph.resize(N, vector<int>(N));
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> graph[y][x];

    checkPiece(0, 0, N);
    for (int count : cnt)
        cout << count << "\n";
}