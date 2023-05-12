#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Declare
#define S (26 * 1)
#define D (26 * 2) - 1
#define MAX (2e9)
#define SIZE (26 * 2)

// Graph
vector<vector<int>> C(SIZE, vector<int>(SIZE));
vector<vector<int>> F(SIZE, vector<int>(SIZE));
vector<vector<int>> graph(SIZE);

int MaxFlow() {
    int flow = 0;

    while (true) {
        queue<int> que;
        que.push(S);

        vector<int> pre(SIZE, -1);
        while (!que.empty()) {
            const int cur = que.front();
            que.pop();

            for (const int& next: graph[cur]) {
                if (!(F[cur][next] < C[cur][next] && pre[next] == -1))
                    continue;
                pre[next] = cur;
                que.push(next);
            }
        }
        // Path not found
        if (pre[D] == -1) break;

        int _flow = MAX;
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

    int N;
    cin >> N;
    while (N--) {
        char _S, _D; int _C;
        cin >> _S >> _D >> _C;

        // 'a' -> 0, 'A' -> 26
        _S -= (_S >= 'a') ? 'a' : 'A' - 26;
        _D -= (_D >= 'a') ? 'a' : 'A' - 26;

        // Capacity
        C[_S][_D] += _C;
        C[_D][_S] += _C;

        // Link
        graph[_S].push_back(_D);
        graph[_D].push_back(_S);
    }
    cout << MaxFlow();
}