#include <iostream>
#include <vector>
using namespace std;

vector<bool> visit;
vector<vector<int>> graph;

void DFS(const int& u) {
    visit[u] = true;

    for (int v : graph[u])
        if (!visit[v])
            DFS(v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    visit.resize(N + 1);
    graph.resize(N + 1);

    int u, v;
    while (M--) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int cnt = 0;
    while (N--) {
        if (!visit[N + 1]) {
            DFS(N + 1);
            cnt++;
        }
    }

    cout << cnt;
}