#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(const int& N) {
    queue<int> que;
    vector<bool> visit(N + 1);

    que.push(N);

    int depth = 0;
    int num, amount;
    while (!que.empty()) {
        int amount = que.size();

        for (int i = 0; i < amount; i++) {
            num = que.front();
            que.pop();

            if (num == 0) return depth;
            if (num >= 5 && !visit[num - 5]) {
                visit[num - 5] = true;
                que.push(num - 5);
            }
            if (num >= 3 && !visit[num - 3]) {
                visit[num - 3] = true;
                que.push(num - 3);
            }
        }

        depth++;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    cout << BFS(N);
}