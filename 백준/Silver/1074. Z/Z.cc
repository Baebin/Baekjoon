#include <iostream>
#include <algorithm>
using namespace std;

#define X loc.x + (dx[i] * (len / 2))
#define Y loc.y + (dy[i] * (len / 2))

int r, c;

// Left, Right, DownLeft, DownRight
int dx[4] = { 0, 1, 0, 1 };
int dy[4] = { 0, 0, 1, 1 };

struct Location {
    int x, y;

    bool equal(const Location& loc) {
        if (x == loc.x && y == loc.y)
            return true;
        return false;
    }
};

int cnt = 0;
void search(Location loc, const int& len) {
    if (loc.equal({ c, r })) {
        cout << cnt;
        return;
    }
    if (c < loc.x + len && r < loc.y + len
        && c >= loc.x && r >= loc.y) {
        for (int i = 0; i < 4; i++)
            search({ X, Y }, len / 2);
        return;
    }
    cnt += len * len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N >> r >> c;

    search({ 0, 0 }, (1 << N));
}