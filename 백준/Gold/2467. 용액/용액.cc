#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Declare
#define INF 2e9

void search(const int& N, const vector<int>& vec) {
    int left = 0;
    int right = N - 1;

    int min = INF;
    int idx_left, idx_right;
    while (left < right) {
        int tmp = vec[left] + vec[right];
        if (abs(tmp) <= min) {
            idx_left = left;
            idx_right = right;
            min = abs(tmp);
        }

        if (tmp == 0)
            break;
        if (tmp < 0)
            left++;
        else right-- ;
    }

    cout << vec[idx_left] << " " << vec[idx_right];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());

    search(N, vec);
}