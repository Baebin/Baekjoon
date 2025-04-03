#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int cnt, lamp;
    vector<vector<int>> switches(N);
    vector<int> connectedLamps(M + 1);
    for (int i = 0; i < N; i++) {
        cin >> cnt;
        while (cnt-- && cin >> lamp)
            switches[i].emplace_back(lamp),
            connectedLamps[lamp]++;
    }

    for (vector<int> lamps : switches) {
        bool can = true;
        for (int lamp : lamps) {
            if (connectedLamps[lamp] - 1)
                continue;
            can = false;
            break;
        }
        if (can) {
            cout << 1 << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
}
