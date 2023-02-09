#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <queue>
#include <map>
using namespace std;

void pop(bool isMin, priority_queue<int>* max_que, priority_queue<int, vector<int>, greater<int>>* min_que, map<int, int>* cnt) {
    int num;

    if (isMin) {
        if ((*min_que).empty()) return;
        num = (*min_que).top();
    }
    else {
        if ((*max_que).empty()) return;
        num = (*max_que).top();
    }
    (*cnt)[num]--;

    // Empty Number Delete
    while (!(*min_que).empty() && (*cnt)[(*min_que).top()] == 0)
        min_que->pop();
    while (!(*max_que).empty() && (*cnt)[(*max_que).top()] == 0)
        max_que->pop();

    // Number Delete
    if (!(*min_que).empty() && (*min_que).top() == num)
        min_que->pop();
    if (!(*max_que).empty() && (*max_que).top() == num)
        max_que->pop();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        map<int, int> cnt;
        priority_queue<int> max_que;
        priority_queue<int, vector<int>, greater<int>> min_que;

        while (K--) {
            char cmd;
            int num;

            cin >> cmd >> num;
            if (cmd == 'I') {
                cnt[num]++;
                max_que.push(num);
                min_que.push(num);
            }
            else pop(num == -1, &max_que, &min_que, &cnt);
        }

        if (max_que.empty() || min_que.empty()) cout << "EMPTY" << "\n";
        else cout << max_que.top() << " " << min_que.top() << "\n";
    }
}