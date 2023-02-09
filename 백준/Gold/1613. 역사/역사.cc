#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Node
int N;

vector<vector<int>> graph;

void floydWarshall() {
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> N >> K;
    graph.resize(N + 1, vector<int>(N + 1));

    int A, B;
    while (K--) {
        cin >> A >> B;
        graph[A][B] = 1;
    }

    floydWarshall();

    int S;
    cin >> S;
    while (S--) {
        cin >> A >> B;

        if (graph[A][B]) cout << -1 << "\n";
        else if (graph[B][A]) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}