#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

bool run(const char& cmd, deque<int>* que, bool *is_reversed) {
    if (cmd == 'R')
        *is_reversed = !*is_reversed;
    else {
        if ((*que).empty())
            return false;
        if (*is_reversed)
            (*que).pop_back();
        else (*que).pop_front();
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    string cmd, num;
    deque<int> que;

    int N, idx, tmp;
    for (int i = 0; i < T; i++) {
        cin >> cmd >> N >> num;

        idx = num.length(), tmp = 0;
        for (int j = 0; j < idx; j++) {
            if (num[j] >= '0' && num[j] <= '9') {
                tmp *= 10;
                tmp += num[j] - '0';
            } else {
                if (tmp != 0)
                    que.push_back(tmp);
                tmp = 0;
            }
        }

        bool error = false;
        bool is_reversed = false;
        for (char c : cmd) {
            if (!run(c, &que, &is_reversed)) {
                error = true;
                break;
            }
        }

        if (error) {
            cout << "error\n";
            continue;
        }

        if (is_reversed)
            reverse(que.begin(), que.end());
        
        cout << "[";
        while (!que.empty()) {
            cout << que.front();
            que.pop_front();

            if (!que.empty())
                cout << ",";
        }
        cout << "]\n";
    }
}