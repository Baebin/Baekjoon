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

pair<int, int> BFS(const int& N, const int& K) {
    queue<Location> que;
    vector<bool> visit(MAX + 1);

    que.push({ N, 0 });

    int cnt = 0;
    int result = -1;

    while (!que.empty()) {
        Location loc = que.front();
        que.pop();

        visit[loc.x] = true;

        if (loc.x == K) {
            if (result == -1) {
                result = loc.cnt;
                cnt++;
            }
            else if (loc.cnt == result)
                cnt++;
        }
        loc.cnt++;

        if (loc.x * 2 <= MAX && !visit[loc.x * 2])
            que.push({ loc.x * 2, loc.cnt });
        if (loc.x + 1 <= MAX && !visit[loc.x + 1])
            que.push({ loc.x + 1, loc.cnt });
        if (loc.x - 1 >= 0 && !visit[loc.x - 1])
            que.push({ loc.x - 1, loc.cnt });
    }

    return { result, cnt };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    pair<int, int> data = BFS(N, K);
    cout << data.first << "\n" << data.second;
}