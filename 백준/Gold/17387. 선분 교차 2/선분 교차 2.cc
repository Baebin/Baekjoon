#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Structure
typedef pair<long long, long long> Location;

int CCW(const Location& l1, const Location& l2, const Location& l3) {
    // 신발끈 공식
    long long weight
        = (l1.first * l2.second) + (l2.first * l3.second) + (l3.first * l1.second)
        - ((l1.second * l2.first) + (l2.second * l3.first) + (l3.second * l1.first));
    return (weight == 0 ? 0 : (weight > 0 ? 1 : -1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Location loc[4];
    for (int i = 0; i < 4; i++) {
        long long x, y;
        cin >> x >> y;
        loc[i] = { x, y };
    }

    // p1, p2, p3
    int c1 = CCW(loc[0], loc[1], loc[2]);
    // p1, p2, p4
    int c2 = CCW(loc[0], loc[1], loc[3]);

    // p3, p4, p1
    int c3 = CCW(loc[2], loc[3], loc[0]);
    // p3, p4, p2
    int c4 = CCW(loc[2], loc[3], loc[1]);

    // 일직선상
    if (c1 * c2 == 0 && c3 * c4 == 0) {
        if (loc[0] > loc[1])
            swap(loc[0], loc[1]);
        if (loc[2] > loc[3])
            swap(loc[2], loc[3]);
        // A <= D && B >= C
        if (loc[0] <= loc[3] && loc[1] >= loc[2])
            cout << 1;
        else cout << 0;
    }
    else if (c1 * c2 <= 0 && c3 * c4 <= 0)
        cout << 1;
    else cout << 0;
}