#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Binary Search
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

    // Init
    vector<int> num(N);
    vector<int> sequence, idx(N);
    for (register int i = 0; i < N; i++)
        cin >> num[i];

    idx[0] = 1;
    int size_sequence = 1;
    sequence.push_back(num[0]);

    // LIS (n log n)
    for (register int i = 1; i < N; i++) {
        if (sequence.back() < num[i]) {
            sequence.push_back(num[i]);
            idx[i] = ++size_sequence;
        }
        else {
            int _idx = lowerBound(sequence, num[i]);
            sequence[_idx] = num[i];
            idx[i] = (_idx + 1);
        }
    }

    // Search (using idx)
    stack<int> st;
    int cur = size_sequence;
    for (register int i = N - 1; i >= 0 && cur; i--) {
        if (idx[i] != cur) continue;
        st.push(num[i]); cur--;
    }

    // Print
    cout << size_sequence << "\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}