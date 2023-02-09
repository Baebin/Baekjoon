#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Structure
typedef long long ll;
typedef pair<ll, ll> Location;

int CCW(const Location& l1, const Location& l2, const Location& l3) {
    // 신발끈 공식
    ll weight
        = (l1.first * l2.second) + (l2.first * l3.second) + (l3.first * l1.second)
        - ((l1.second * l2.first) + (l2.second * l3.first) + (l3.second * l1.first));
    return (weight == 0 ? 0 : (weight > 0 ? 1 : -1));
}

void printLoc(const Location& l1, const Location& l2, const Location& l3, const Location& l4) {
    // dx. (x1y2 - y1x2) * (x3 - x4) - (x1 - x2) * (x3y4 - y3x4)
    // dy. (x1y2 - y1x2) * (y3 - y4) - (y1 - y2) * (x3y4 - y3x4)
    // d. (x1 - x2)(y3 - y4) - (y1 - y2)(x3 - x4)
    double dx = (l1.first * l2.second - l1.second * l2.first) * (l3.first - l4.first)
        - (l1.first - l2.first) * (l3.first * l4.second - l3.second * l4.first);
    double dy = (l1.first * l2.second - l1.second * l2.first) * (l3.second - l4.second)
        - (l1.second - l2.second) * (l3.first * l4.second - l3.second * l4.first);
    double d = (l1.first - l2.first) * (l3.second - l4.second)
        - (l1.second - l2.second) * (l3.first - l4.first);

    cout << 1 << "\n";

    cout << fixed;
    cout.precision(9);
    if (d == 0) {
        // A <= B = C <= D
        if (l1 <= l3 && l2 == l3) cout << l2.first << " " << l2.second;
        // C <= D = A <= B
        else if (l3 <= l1 && l4 == l1) cout << l1.first << " " << l1.second;
    } else cout << dx / d << " " << dy / d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Location loc[4];
    for (int i = 0; i < 4; i++) {
        ll x, y;
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
        // A <= (C <= B) <= D
        if (loc[0] <= loc[3] && loc[2] <= loc[1])
            printLoc(loc[0], loc[1], loc[2], loc[3]);
        else cout << 0;
    }
    else if (c1 * c2 <= 0 && c3 * c4 <= 0)
        printLoc(loc[0], loc[1], loc[2], loc[3]);
    else cout << 0;
}