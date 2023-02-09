#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

// Declare
#define INF 2e9

int serach(const vector<int>& vec, const int& S) {
    int N = vec.size() - 1, len = INF;
    int sum = vec[0], start = 0, end = 0;
    while (start <= end && end <= N) {
        if (sum >= S)
            len = min(len, (end - start) + 1);
        if (sum < S && end != N)
            sum += vec[++end];
        else
            sum -= vec[start++];
    }
    return (len == INF ? 0 : len);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S;
    cin >> N >> S;

    vector<int> vec(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];
    cout << serach(vec, S);
}