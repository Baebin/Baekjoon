#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Location {
    int x, y;
};

bool cmp(const Location &a, const Location &b) {
    if (a.y == b.y)
        return a.x < b.x;
    return a.y < b.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<Location> vec;

    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;

        vec.push_back({ x, y });
    }

    sort(vec.begin(), vec.end(), cmp);
    for (Location loc : vec)
        cout << loc.x << " " << loc.y << "\n";
}