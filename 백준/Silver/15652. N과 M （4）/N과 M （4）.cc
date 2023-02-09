#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <queue>
using namespace std;

// Declare
#define MAX 8

// Size, Depth
int N, M;

struct Location {
    int x, depth;
    queue<int> log;
};

void DFS(Location loc) {
    if (loc.depth == M) {
        while (!loc.log.empty()) {
            cout << loc.log.front() << " ";
            loc.log.pop();
        }
        cout << "\n";
        return;
    }

    for (int i = loc.x; i <= N; i++) {
        queue<int> log = loc.log;
        log.push(i);

        DFS({ i, loc.depth + 1, log });
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    DFS({ 1, 0 });
}