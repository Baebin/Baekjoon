#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<bool> visit;
vector<vector<int>> graph;

void BFS(const int& start) {
    queue<int> que;

    que.push(start);
    visit[start] = true;

    cout << "\n";
    while (!que.empty()) {
        int vertex = que.front();
        que.pop();

        cout << vertex << " ";
        for (int node : graph[vertex]) {
            if (!visit[node]) {
                que.push(node);
                visit[node] = true;
            }
        }
    }
}

void DFS(const int& vertex) {
    cout << vertex << " ";

    visit[vertex] = true;
    for (int node : graph[vertex])
        if (!visit[node])
            DFS(node);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    visit.resize(N + 1);
    graph.resize(N + 1, vector<int>());

    int start, end;
    while (M--) {
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    for (int i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());

    DFS(V);
    fill(visit.begin(), visit.end(), false);

    BFS(V);
}