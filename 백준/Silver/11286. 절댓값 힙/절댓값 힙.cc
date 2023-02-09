#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <queue>
using namespace std;

struct cmp {
    // Reverse
    bool operator()(int a, int b) {
        if (abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, cmp> que;

    int N;
    cin >> N;

    int x;
    while (N--) {
        cin >> x;
        if (x == 0) {
            if (que.empty())
                cout << 0 << "\n";
            else {
                cout << que.top() << "\n";
                que.pop();
            }
        }
        else que.push(x);
    }
}