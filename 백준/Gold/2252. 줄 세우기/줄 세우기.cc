#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

vector<int> inDegree;
vector<vector<int>> outDegree;

void topologySort() {
    vector<int> result;
    queue<int> que;

    // 진입 차수 Zero
    for (int i = 1; i <= N; i++)
        if (inDegree[i] == 0)
            que.push(i);

    for (int i = 1; i <= N; i++) {
        if (que.empty())
            break;
        int vertex = que.front();
        result.push_back(vertex);
        que.pop();

        for (int node : outDegree[vertex])
            if (--inDegree[node] == 0)
                que.push(node);
    }

    for (int node : result)
        cout << node << " ";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    inDegree.resize(N + 1);
    outDegree.resize(N + 1, vector<int>());

    int A, B;
    while (M--) {
        cin >> A >> B;

        outDegree[A].push_back(B);
        inDegree[B]++;
    }

    topologySort();
}