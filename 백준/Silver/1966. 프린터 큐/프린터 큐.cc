#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int N, M;
    int weight;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;

        // Init
        queue<pair<int, int>> que;
        priority_queue<int> pq;

        for (int j = 0; j < N; j++) {
            cin >> weight;
            que.push({ weight, j });
            pq.push(weight);
        }

        int pos = 0;
        while (!que.empty()) {
            if (pq.top() == que.front().first) {
                pos++;

                if (que.front().second == M) {
                    cout << pos << "\n";
                    break;
                }

                pq.pop();
                que.pop();

                continue;
            }

            que.push(que.front());
            que.pop();
        }
    }
}