#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <queue>
using namespace std;

// Declare
#define MAX 10000

// Command List
const char cmd[4] = { 'D', 'S', 'L', 'R' };

class DSLR {
public:
    DSLR(const int& num) { this->num = num; }
    DSLR(const int& num, const string& log) {
        this->num = num;
        this->log = log;
    }
    int run(const char& cmd) {
        if (cmd == 'D')
            return (num * 2) % 10000;
        if (cmd == 'S')
            return (num == 0) ? MAX - 1 : num - 1;
        if (cmd == 'L')
            return (num % 1000) * 10 + (num / 1000);
        if (cmd == 'R')
            return (num % 10) * 1000 + (num / 10);
        return num;
    }
    int getNum() { return num; }
    string getLog() { return log; }
private:
    int num;
    string log;
};

string BFS(DSLR dslr, const int& b) {
    queue<DSLR> que;
    que.push(dslr);

    vector<int> visit(MAX);
    visit[dslr.getNum()] = true;

    while (!que.empty()) {
        dslr = que.front();
        que.pop();

        if (dslr.getNum() == b)
            break;

        for (int i = 0; i < 4; i++) {
            int next = dslr.run(cmd[i]);
            if (visit[next])
                continue;
            visit[next] = true;

            string log = dslr.getLog();
            log.push_back(cmd[i]);

            que.push(DSLR(next, log));
        }
    }

    return dslr.getLog();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;
        cout << BFS(DSLR(A), B) << "\n";
    }
}