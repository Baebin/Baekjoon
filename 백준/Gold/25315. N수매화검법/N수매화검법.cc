#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

class Location {
public:
    ll x, y;

    bool operator>(const Location& a) {
        if (x == a.x)
            return (y > a.y);
        return (x > a.x);
    }

    bool operator<=(const Location& a) {
        if (x == a.x && y == a.y)
            return true;
        if (x == a.x)
            return (y < a.y);
        return (x < a.x);
    }
};

class Line {
public:
    ll x1, x2, y1, y2, w;

    bool operator<(const Line& a) {
        if (w != a.w)
            return w < a.w;
        if (x1 == a.x1) {
            if (y1 == a.y1) {
                if (x2 == a.x2) {
                    return y2 < a.y2;
                }
                return x2 < a.x2;
            }
            return (y1 < a.y1);
        }
        return (x1 < a.x1);
    }
};

int CCW(const Location& a, const Location &b, const Location &c) {
    ll ccw = ((a.x * b.y) + (b.x * c.y) + (c.x * a.y))
             - ((a.y * b.x) + (b.y * c.x) + (c.y * a.x));
    if (ccw < 0) return -1;
    if (ccw == 0) return 0;
    return 1;
}

bool check(Location a, Location b, Location c, Location d) {
    int a1 = CCW(a, b, c);
    int a2 = CCW(a, b, d);

    int c1 = CCW(c, d, a);
    int c2 = CCW(c, d, b);

    if (a1 * a2 == 0 && c1 * c2 == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return (a <= d && c <= b);
    }
    return (a1 * a2 <= 0 && c1 * c2 <= 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<Line> lines(N);

    for (int i = 0; i < N; i++) {
        ll x1, x2, y1, y2, w;
        cin >> x1 >> y1 >> x2 >> y2 >> w;

        lines[i] = Line{ x1, x2, y1, y2, w };
    }
    sort(lines.begin(), lines.end());

    ll sum = 0;
    for (int i = 0; i < N; i++) {
        sum += lines[i].w;
        Location a = { lines[i].x1, lines[i].y1 };
        Location b = { lines[i].x2, lines[i].y2 };
        for (int j = i + 1; j < N; j++) {
            Location c = { lines[j].x1, lines[j].y1 };
            Location d = { lines[j].x2, lines[j].y2 };
            if (check(a, b, c, d)) sum += lines[i].w;
        }
    }
    cout << sum;
}