#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Declare
#define INF 2e9

// Structure
struct Location {
    int x, y;

    bool operator==(const Location& loc) {
        return (x == loc.x && y == loc.y);
    }
    int getDistance(const Location& loc) {
        return sqrt((x - loc.x) * (x - loc.x) + (y - loc.y) * (y - loc.y));
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<Location> vec(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        vec[i] = { x, y };
    }

    Location res;
    int minimum = INF;
    for (Location loc : vec) {
        int max = 0;
        for (Location loc_tmp : vec) {
            if (loc == loc_tmp)
                continue;
            int dis = loc.getDistance(loc_tmp);
            if (dis > max)
                max = dis;
        }
        if (minimum > max) {
            minimum = max;
            res = loc;
        }
    }
    cout << res.x << " " << res.y;
}