#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define INF 2e9

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, R;
    cin >> N >> M >> R;

    vector<int> items(N + 1);
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
    for (int i = 1; i <= N; i++) {
        cin >> items[i];
        dist[i][i] = 0;
    }

    while (R--) {
        int a, b, l;
        cin >> a >> b >> l;
        dist[a][b] = l;
        dist[b][a] = l;
    }
    // Floyd Warshall
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (dist[i][k] != INF && dist[k][j] != 0)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        int item = 0;
        for (int j = 1; j <= N; j++)
            if (dist[i][j] <= M)
                item += items[j];
        // Item Count
        cnt = max(cnt, item);
    }
    cout << cnt;
}