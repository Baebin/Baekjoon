#include <iostream>
#include <vector>
using namespace std;

vector<bool> visit;
vector<vector<int>> network;

// DFS Count
int cnt = 0;

void DFS(int computer) {
    visit[computer] = true;

    for (int next : network[computer]) {
        if (!visit[next]) {
            DFS(next);
            cnt++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    visit.resize(N + 1);
    network.resize(N + 1);

    int start, end;
    while (M--) {
        cin >> start >> end;
        network[start].push_back(end);
        network[end].push_back(start);
    }

    DFS(1);
    cout << cnt;
}