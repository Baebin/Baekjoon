#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declear
#define INF 2e9

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));

    int A, B;
    while (M--) {
        cin >> A >> B;

        graph[A][B] = 1;
        graph[B][A] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                if (graph[i][k] == INF || graph[k][j] == INF)
                    continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    int idx;
    int min = INF;

    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            sum += graph[i][j];
        }

        if (min > sum) {
            min = sum;
            idx = i;
        }
    }

    cout << idx;
}