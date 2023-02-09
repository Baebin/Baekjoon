#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000

struct Location {
    int x, cnt;
};

int BFS(const int& N, const int& K) {
    queue<Location> que;
    vector<bool> visit(MAX + 1);

    que.push({ N, 0 });

    Location loc;
    while (!que.empty()) {
        loc = que.front();
        que.pop();

        if (loc.x == K)
            break;
        loc.cnt++;

        if (loc.x + 1 <= MAX && !visit[loc.x + 1]) {
            que.push({ loc.x + 1, loc.cnt });
            visit[loc.x + 1] = true;
        }
        if (loc.x - 1 >= 0 && !visit[loc.x - 1]) {
            que.push({ loc.x - 1, loc.cnt });
            visit[loc.x - 1] = true;
        }
        if (loc.x * 2 <= MAX && !visit[loc.x * 2]) {
            que.push({ loc.x * 2, loc.cnt });
            visit[loc.x * 2] = true;
        }
    }

    return loc.cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    cout << BFS(N, K);
}