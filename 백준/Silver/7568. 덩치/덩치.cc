#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Size {
    int x, y;
};

bool cmp(const Size &a, const Size &b) {
    if (a.x < b.x && a.y < b.y)
        return true;
    return false;
}

int N;
void ranking(const vector<Size>& size, vector<int> *rank) {
    Size a, b;
    for (int i = 0; i < N; i++) {
        a = size[i];
        for (Size b : size)
            if (cmp(a, b))
                (*rank)[i] += 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    N;
    cin >> N;

    vector<Size> size(N);
    vector<int> rank(N, 1);

    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        size[i] = { x, y };
    }

    ranking(size, &rank);
    for (int i = 0; i < N; i++)
        cout << rank[i] << " ";
}