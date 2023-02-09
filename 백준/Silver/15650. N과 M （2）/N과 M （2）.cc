#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Declare
#define MAX 8

// Visit
vector<int> visit;

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
        if (!visit[i]) {
            queue<int> log = loc.log;
            log.push(i);

            visit[i] = true;
            DFS({ i, loc.depth + 1, log });
            visit[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    visit.resize(N + 1);

    DFS({ 1, 0 });
}