#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

// Structure
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    ll ans = 0;
    if (N != 0) {
        priority_queue<int> pqM;
        priority_queue<int, vector<int>, greater<int>> pqm;
        for (int i = 0; i < N; i++) {
            int opinion;
            cin >> opinion;

            ans += opinion;
            pqm.push(opinion);
            pqM.push(opinion);
        }

        // size
        int cnt = round(N * 0.15);
        const int& cnts = N - (cnt * 2);

        // remove
        while (cnt--) {
            ans -= pqm.top() + pqM.top();
            pqm.pop();
            pqM.pop();
        }
        ans = round(ans / (float)cnts);
    }
    cout << ans;
}