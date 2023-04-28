#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> que;
    while (N--) {
        int num;
        cin >> num;
        que.push(num);
    }

    int before = 0;
    while (!que.empty()) {
        if (before != que.top())
            cout << (before = que.top()) << " ";
        que.pop();
    }
}