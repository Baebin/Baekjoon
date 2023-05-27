#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> C, F;
vector<vector<int>> graph;

int MaxFlow() {
    int flow = 0;
    while (true) {
        vector<int> pre(N + 1, -1);

        queue<int> que;
        que.push(1);
        while (!que.empty()) {
            int cur = que.front();
            que.pop();

            for (const int& next: graph[cur]) {
                if (!(F[cur][next] < C[cur][next] && pre[next] == -1))
                    continue;
                pre[next] = cur;
                que.push(next);
            }
        }
        if (pre[N] == -1) break;

        int f = 2e9;
        for (register int cur = N; cur != 1; cur = pre[cur])
            f = min(f, C[pre[cur]][cur] - F[pre[cur]][cur]);
        for (register int cur = N; cur != 1; cur = pre[cur]) {
            F[pre[cur]][cur] += f;
            F[cur][pre[cur]] -= f;
        }
        flow += f;
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    graph.resize(N + 1);
    C.resize(N + 1, vector<int>(N + 1));
    F.resize(N + 1, vector<int>(N + 1));

    while (M--) {
        int _A, _B, _C;
        cin >> _A >> _B >> _C;

        graph[_A].emplace_back(_B);
        graph[_B].emplace_back(_A);
        C[_A][_B] += _C;
        C[_B][_A] += _C;
    }
    cout << MaxFlow();
}