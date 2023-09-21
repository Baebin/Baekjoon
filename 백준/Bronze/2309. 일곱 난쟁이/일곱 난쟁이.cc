#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec; int sum = 0;
    for (register int i = 0; i < 9; i++) {
        int N; cin >> N; sum += N;
        vec.emplace_back(N);
    }
    sort(vec.begin(), vec.end());

    for (register int i = 0; i < 9; i++) {
        for (register int j = i + 1; j < 9; j++) {
            if (sum - (vec[i] + vec[j]) != 100)
                continue;
            for (register int k = 0; k < 9; k++) {
                if (k == i || k == j)
                    continue;
                cout << vec[k] << '\n';
            }
            return 0;
        }
    }
}