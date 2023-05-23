#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lowerBound(const vector<int>& num, const int& value) {
    int low = -1, high = num.size();

    while (low + 1 < high) {
        int mid = (low + high) / 2;
        if (num[mid] < value) low = mid;
        else high = mid;
    }
    return high;
}

int main() {
    int N;
    cin >> N;

    vector<int> num(N);
    for (register int i = 0; i < N; i++)
        cin >> num[i];

    vector<int> sequence;
    sequence.push_back(num[0]);
    for (register int i = 1; i < N; i++) {
        if (sequence.back() < num[i])
            sequence.push_back(num[i]);
        else {
            int idx = lowerBound(sequence, num[i]);
            sequence[idx] = num[i];
        }
    }
    cout << sequence.size() << "\n";
}