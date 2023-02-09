#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> vec(N + 1);
    for (int i = 0; i < N; i++)
        cin >> vec[i];

    int sum = vec[0];
    for (int i = 1; i < N; i++) {
        if (vec[i - 1] + 1 != vec[i])
            sum += vec[i];
    }

    cout << sum;
}