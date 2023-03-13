#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// Structure
struct Line {
    int h, o;
    bool operator<(const Line &line) {
        if (o == line.o)
            return h < line.h;
        return o < line.o;
    }
};

int sweeping(const int &N, const int &D, vector<Line> &lines) {
    sort(lines.begin(), lines.end());

    // Min Heap
    priority_queue<int, vector<int>, greater<int>> que;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int left = lines[i].h;
        int right = lines[i].o;
        int length = right - left;

        if (length > D)
            continue;
        que.push(left);

        while (!que.empty()) {
            int len_cur = right - que.top();
            if (len_cur <= D)
                break;
            que.pop();
        }
        cnt = max(cnt, (int) que.size());
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // Number of Lines
    int N;
    cin >> N;

    vector<Line> lines(N);
    for (int i = 0; i < N; i++) {
        int H, O;
        cin >> H >> O;

        // H <= O
        if (H > O)
            swap(H, O);
        lines[i] = Line{ H, O };
    }

    // Length of Line
    int D;
    cin >> D;

    cout << sweeping(N, D, lines);
}