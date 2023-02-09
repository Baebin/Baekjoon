#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 4000
#define INPUT const vector<int>& vec

int avg(INPUT) {
    int _sum = 0;
    for (int i : vec)
        _sum += i;
    return round(_sum / (double)vec.size());
}

int mid(INPUT) {
    return vec[vec.size() / 2];
}

int many(INPUT) {
    vector<int> _many(MAX * 2 + 1);

    bool isFirst;
    int max = 0, num;
    for (int i : vec) {
        _many[i + MAX]++;
        if (_many[i + MAX] > max) {
            isFirst = false;

            num = i;
            max = _many[i + MAX];
        }
        else if (_many[i + MAX] == max
            && !isFirst) {
            isFirst = true;

            num = i;
        }
    }

    return num;
}

int ran(INPUT) {
    return vec.back() - vec.front();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int sum = 0;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
        sum += vec[i];
    }

    sort(vec.begin(), vec.end());
    cout << avg(vec) << "\n";
    cout << mid(vec) << "\n";
    cout << many(vec) << "\n";
    cout << ran(vec);
}