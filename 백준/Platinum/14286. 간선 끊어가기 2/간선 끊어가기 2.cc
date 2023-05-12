#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Declare
#define MAX 2e9

// Capacity, Flow
vector<vector<int>> C, F;
vector<vector<int>> graph;

int MaxFlow(const int &S, const int& T, const int& N) {
    int flow = 0;

    while (true) {
        // Previous Route
        vector<int> pre(N, -1);

        queue<int> que;
        que.push(S);
        while (!que.empty()) {
            int cur = que.front();
            que.pop();

            for (const int& next : graph[cur]) {
                if (!(F[cur][next] < C[cur][next] && pre[next] == -1))
                    continue;
                pre[next] = cur;
                que.push(next);
            }
        }
        // Route - Empty
        if (pre[T] == -1) break;

        int _flow = MAX;
        for (register int cur = T; cur != S; cur = pre[cur])
            _flow = min(_flow, C[pre[cur]][cur] - F[pre[cur]][cur]);
        for (register int cur = T; cur != S; cur = pre[cur]) {
            F[pre[cur]][cur] += _flow;
            F[cur][pre[cur]] -= _flow;
        }
        flow += _flow;
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    graph.resize(N + 1);
    C.resize(N + 1, vector<int>(N + 1));
    F.resize(N + 1, vector<int>(N + 1));

    while (M--) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back(b);
        graph[b].push_back(a);

        C[a][b] = C[b][a] = c;
    }

    int S, T;
    cin >> S >> T;
    cout << MaxFlow(S, T, N + 1);
}