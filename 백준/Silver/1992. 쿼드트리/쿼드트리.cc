#include <iostream>
#include <vector>
using namespace std;

#define X loc.x + (dx[i] * len / 2)
#define Y loc.y + (dy[i] * len / 2)

// Size
int N;

// Movie
vector<vector<int>> graph;

// Left, Right, DownL, DownR
int dx[4] =  { 0, 1, 0, 1 };
int dy[4] = { 0, 0, 1, 1 };

// Structure
struct Location {
    int x, y;
};

void divide(const Location& loc, const int& len) {
    int color = graph[loc.y][loc.x];

    for (int y = loc.y; y < loc.y + len; y++) {
        for (int x = loc.x; x < loc.x + len; x++) {
            if (color == graph[y][x])
                continue;
            cout << "(";
            for (int i = 0; i < 4; i++)
                divide({ X, Y }, len / 2);
            cout << ")";
            return;
        }
    }
    cout << color;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    graph.resize(N, vector<int>(N));

    string str;
    for (int y = 0; y < N; y++) {
        cin >> str;
        for (int x = 0; x < N; x++)
            graph[y][x] = str[x] == '1';
    }
    divide({ 0, 0 }, N);
}