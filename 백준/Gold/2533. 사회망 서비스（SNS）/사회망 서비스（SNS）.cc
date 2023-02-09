#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// DFS Variables
vector<bool> visit;
vector<vector<int>> dp;
vector<vector<int>> graph;

void DFS(const int& root) {
    visit[root] = true;
    dp[root][1] = 1;

    int size = graph[root].size();
    for (int idx = 0; idx < size; idx++) {
        int node = graph[root][idx];
        if (visit[node])
            continue;
        DFS(node);

        // 0: 일반인, 1: 얼리 아답터
        dp[root][0] += dp[node][1];
        dp[root][1] += min(dp[node][0], dp[node][1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    graph.resize(N + 1);
    visit.resize(N + 1);

    dp.resize(N + 1, vector<int>(2));
    while (N-- > 1) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    DFS(1);
    cout << min(dp[1][0], dp[1][1]);
}