#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

struct Location {
    double x, y;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<Location> vec(N + 1);
    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        vec[i] = { x, y };
    }
    vec[N] = vec[0];

    double sum = 0;
    for (int i = 0; i < N; i++)
        // 신발끈 공식
        sum += (vec[i].y * vec[i + 1].x - vec[i].x * vec[i + 1].y) / 2;

    cout << fixed;
    cout.precision(1);

    cout << abs(sum);
}