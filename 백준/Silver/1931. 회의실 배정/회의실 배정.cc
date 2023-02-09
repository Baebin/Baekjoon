#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Time {
    int start, end;
};

bool cmp(const Time& a, const Time& b) {
    if (a.end == b.end)
        return a.start < b.start;
    return a.end < b.end;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<Time> vec(N);
    
    int start, end;
    while (N--) {
        cin >> start >> end;
        vec[N] = { start, end };
    }

    sort(vec.begin(), vec.end(), cmp);

    int cnt = 0; end = 0;
    for (Time time : vec) {
        if (end <= time.start) {
            end = time.end;
            cnt++;
        }
    }

    cout << cnt;
}