#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <queue>
using namespace std;

struct Score {
    int score, num;

    bool operator<(const Score& s) const {
        return (score < s.score);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<Score> que;
    for (int i = 1; i <= 8; i++) {
        int num;
        cin >> num;
        que.push(Score{ num, i });
    }

    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> queue;
    for (int i = 1; i <= 5; i++) {
        Score sc = que.top();
        sum += sc.score;
        queue.push(sc.num);
        que.pop();
    }

    cout << sum << "\n";
    while (!queue.empty()) {
        cout << queue.top() << " ";
        queue.pop();
    }
}