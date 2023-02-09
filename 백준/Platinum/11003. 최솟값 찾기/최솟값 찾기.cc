#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct Location {
    int x, pos;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    vector<int> vec(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];
    
    deque<Location> que;
    for (int i = 0; i < N; i++) {
        if (!que.empty() && i - L + 1 == que.front().pos)
            que.pop_front();
        // 큰 수 모두 제거
        while (!que.empty() && que.back().x > vec[i])
            que.pop_back();
        que.push_back({ vec[i], i + 1 });
        cout << que.front().x << " ";
    }
}