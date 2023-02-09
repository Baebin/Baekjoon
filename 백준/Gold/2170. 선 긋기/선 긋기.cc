#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Declare
#define INF 2e9

// Strucuture
struct Line {
    int x1, x2;

    bool operator<(const Line& line) {
        return x1 < line.x1;
    }
};

int sweeping(vector<Line>* lines) {
    int result = 0, start = -INF, end = -INF;
    sort(lines->begin(), lines->end());

    int N = lines->size();
    for (int i = 0; i < N; i++) {
        if (lines->at(i).x1 <= end)
            end = max(end, lines->at(i).x2);
        else {
            result += end - start;
            start = lines->at(i).x1;
            end = lines->at(i).x2;
        }
    }
    return result += end - start;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<Line> lines(N);
    while (N--) {
        int x1, x2;
        cin >> x1 >> x2;
        lines[N] = { x1, x2 };
    }
    cout << sweeping(&lines);

}