#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, W;

int topologicalSort(const vector<int>& cost, vector<int>* inDegree, const vector<vector<int>>& outDegree) {
    queue<int> que;
    vector<int> dp(N + 1);

    // 진입 차수 Zero
    for (int i = 1; i <= N; i++) {
        if ((*inDegree)[i] == 0) {
            que.push(i);
            dp[i] = cost[i];
        }
    }

    for (int i = 1; i <= N; i++) {
        int vertex = que.front();
        que.pop();

        for (int node : outDegree[vertex]) {
            if (--(*inDegree)[node] == 0)
                que.push(node);
            dp[node] = max(dp[node], dp[vertex] + cost[node]);
        }
    }

    return dp[W];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        cin >> N >> K;

        vector<int> cost(N + 1);
        vector<int> inDegree(N + 1);
        vector<vector<int>> outDegree(N + 1);

        for (int i = 1; i <= N; i++)
            cin >> cost[i];

        int X, Y;
        while (K--) {
            cin >> X >> Y;
            outDegree[X].push_back(Y);
            inDegree[Y]++;
        }
        cin >> W;

        cout << topologicalSort(cost, &inDegree, outDegree) << "\n";
    }
}