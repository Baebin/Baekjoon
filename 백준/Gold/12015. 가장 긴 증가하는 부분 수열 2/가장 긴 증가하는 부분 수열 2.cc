#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

int lowerBound(const vector<int>& vec, const int& num) {
    int low = -1, high = vec.size();

    while (low + 1 < high) {
        int mid = (low + high) / 2;
        if (!(vec[mid] >= num)) low = mid;
        else high = mid;
    }
    return high;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> num(N);
    for (int i = 0; i < N; i++)
        cin >> num[i];

    vector<int> vec;
    vec.push_back(num[0]);
    for (int i = 0; i < N; i++) {
        int last = vec.size() - 1;
        if (num[i] > vec[last])
            vec.push_back(num[i]);
        else {
            int idx = lowerBound(vec, num[i]);
            vec[idx] = num[i];
        }
    }
    cout << vec.size();
}