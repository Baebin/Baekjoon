#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Size
int N;

// Star
vector<vector<char>> star;

// Structure
struct Info {
    int x, y, depth;
};

void setStar(const Info& loc) {
    star[loc.y][loc.x] = '*';
    star[loc.y + 1][loc.x - 1] = '*';
    star[loc.y + 1][loc.x + 1] = '*';
    for (int i = 0; i < 5; i++)
        star[loc.y + 2][(loc.x - 2) + i] = '*';
}

void DFS(const Info& data) {
    // Validate
    if (data.depth == 3) {
        setStar(data);
        return;
    }

    DFS({ data.x, data.y, data.depth / 2 });
    DFS({ data.x - data.depth / 2, data.y + data.depth / 2, data.depth / 2 });
    DFS({ data.x + data.depth / 2, data.y + data.depth / 2, data.depth / 2 });
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    star.resize(N, vector<char>(2 * N - 1, ' '));
    DFS({ N - 1, 0, N });

    for (vector<char> vec : star) {
        for (char dot : vec)
            cout << dot;
        cout << "\n";
    }
}