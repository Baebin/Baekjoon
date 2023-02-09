#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void topologicalSort(const int& N, vector<int>& inDegree, const vector<vector<int>>& outDegree) {
    queue<int> que;
    vector<int> result(N);

    // 진입 차수 Zero
    for (int i = 1; i <= N; i++)
        if (inDegree[i] == 0)
            que.push(i);

    for (int i = 0; i < N; i++) {
        if (que.empty()) {
            cout << 0;
            return;
        }
        int vertex = que.front();
        result[i] = vertex;
        que.pop();

        for (int node : outDegree[vertex])
            if (--inDegree[node] == 0)
                que.push(node);
    }

    for (int position : result)
        cout << position << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> inDegree(N + 1);
    vector<vector<int>> outDegree(N + 1);

    int PD;
    while (M--) {
        cin >> PD;

        int pos, tmp = 0;
        while (PD--) {
            cin >> pos;
            if (tmp != 0) {
                outDegree[tmp].push_back(pos);
                inDegree[pos]++;
            }
            tmp = pos;
        }
    }

    topologicalSort(N, inDegree, outDegree);
}