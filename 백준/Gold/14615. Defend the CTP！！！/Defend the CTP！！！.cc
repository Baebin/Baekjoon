#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> edge, edge_reverse;
vector<vector<bool>> visit;

void bfs() {
    queue<int> que;
    que.push(1);
    visit[0][0] = true;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (const int& next: edge[cur]) {
            if (visit[0][next]) continue;
            visit[0][next] = true;
            que.push(next);
        }
    }
}

void bfs_reverse() {
    queue<int> que;
    que.push(N);
    visit[1][N] = true;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (const int& pre: edge_reverse[cur]) {
            if (visit[1][pre]) continue;
            visit[1][pre] = true;
            que.push(pre);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    edge.resize(N + 1);
    edge_reverse.resize(N + 1);
    visit.resize(2, vector<bool>(N + 1));

    while (M--) {
        int X, Y;
        cin >> X >> Y;
        edge[X].emplace_back(Y);
        edge_reverse[Y].emplace_back(X);
    }
    int T;
    cin >> T;

    bfs();
    bfs_reverse();
    while (T--) {
        int C;
        cin >> C;

        if (visit[0][C] && visit[1][C]) {
            cout << "Defend the CTP" << '\n';
            continue;
        }
        cout << "Destroyed the CTP" << '\n';
    }
}