#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define MAX 100000

struct Location {
    int x, cnt;
};

pair<int, stack<int>> BFS(const int& N, const int& K) {
    queue<Location> que;
    vector<bool> visit(MAX + 1);

    que.push({ N, 0 });

    Location loc;
    vector<int> route(MAX + 1);
    while (!que.empty()) {
        loc = que.front();
        que.pop();

        if (loc.x == K)
            break;
        loc.cnt++;

        if (loc.x * 2 <= MAX && !visit[loc.x * 2]) {
            que.push({ loc.x * 2, loc.cnt });
            visit[loc.x * 2] = true;
            route[loc.x * 2] = loc.x;
        }
        if (loc.x + 1 <= MAX && !visit[loc.x + 1]) {
            que.push({ loc.x + 1, loc.cnt });
            visit[loc.x + 1] = true;
            route[loc.x + 1] = loc.x;
        }
        if (loc.x - 1 >= 0 && !visit[loc.x - 1]) {
            que.push({ loc.x - 1, loc.cnt });
            visit[loc.x - 1] = true;
            route[loc.x - 1] = loc.x;
        }
    }

    stack<int> st;
    while (loc.x != N) {
        st.push(loc.x);
        // Previous Route
        loc.x = route[loc.x];
    }
    st.push(N);

    return { loc.cnt, st };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    auto data = BFS(N, K);
    cout << data.first << "\n";

    while (!data.second.empty()) {
        cout << data.second.top() << " ";
        data.second.pop();
    }
}