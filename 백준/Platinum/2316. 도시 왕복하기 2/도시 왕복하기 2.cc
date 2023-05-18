#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Declare
#define INF 2e9

// Capacity, Flow
vector<vector<int>> C, F;
vector<vector<int>> graph;

int MaxFlow(const int &S, const int& D, const int& N) {
    int flow = 0;

    while (true) {
        // Previous Route
        vector<int> pre((N * 2) + 1, -1);

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
        if (pre[D] == -1) break;

        int _flow = INF;
        for (register int cur = D; cur != S; cur = pre[cur])
            _flow = min(_flow, C[pre[cur]][cur] - F[pre[cur]][cur]);
        for (register int cur = D; cur != S; cur = pre[cur]) {
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

    graph.resize((N * 2) + 1);  
    C.resize((N * 2) + 1, vector<int>((N * 2) + 1));
    F.resize((N * 2) + 1, vector<int>((N * 2) + 1));

    for (register int i = 1; i <= N; i++) {
        // In -> Out
        C[i][i + N] = 1;
        graph[i].push_back(i + N);
        graph[i + N].push_back(i);
    }

    while (M--) {
        int a, b;
        cin >> a >> b;

        // In -> Out
        graph[a].push_back(b + N);
        graph[a + N].push_back(b);

        graph[b].push_back(a + N);
        graph[b + N].push_back(a);

        // Out -> In
        C[a + N][b] = C[b + N][a] = INF;
    }
    cout << MaxFlow(1 + N, 2, N);
}