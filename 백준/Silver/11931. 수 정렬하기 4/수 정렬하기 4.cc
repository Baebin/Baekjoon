#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <queue>
using namespace std;

// Declare
#define endl "\n";


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int> que;

    while (N--) {
        int A;
        cin >> A;
        que.push(A);
    }

    while (!que.empty()) {
        cout << que.top() << endl;
        que.pop();
    }
    return 0;
}
