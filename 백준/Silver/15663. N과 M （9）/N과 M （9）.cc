#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

// Declare
#define MAX 8

// Size, Depth
int N, M;

// Map
vector<int> graph;
vector<bool> visit;

// Exception
map<queue<int>, bool> isPrinted;

struct Location {
    int x, depth;
    queue<int> log;
};

void DFS(Location loc) {
    if (loc.depth == M) {
        if (isPrinted[loc.log])
            return;
        isPrinted[loc.log] = true;
        while (!loc.log.empty()) {
            cout << loc.log.front() << " ";
            loc.log.pop();
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!visit[i]) {
            queue<int> log = loc.log;
            log.push(graph[i]);

            visit[i] = true;
            DFS({ i, loc.depth + 1, log });
            visit[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    graph.resize(N);
    visit.resize(N);

    for (int i = 0; i < N; i++)
        cin >> graph[i];
    sort(graph.begin(), graph.end());

    DFS({ 0, 0 });
}