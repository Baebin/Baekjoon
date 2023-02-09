#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

void floydWarshall(const int& N, vector<vector<int>>* graph) {
    for (int k = 0; k < N; k++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if ((*graph)[i][k] && (*graph)[k][j])
                    (*graph)[i][j] = 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> graph(N, vector<int>(N));

    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> graph[y][x];

    floydWarshall(N, &graph);
    for (vector<int> vec : graph) {
        for (int path : vec)
            cout << path << " ";
        cout << "\n";
    }
}