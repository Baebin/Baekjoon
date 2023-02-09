#include <iostream>
#include <vector>
using namespace std;

void check(int* stack, vector<int> vec, long long length) {
    *stack = 0;
    for (int len : vec)
        *stack += len / length;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int length;
    cin >> length;

    vector<int> lans(N);
    for (int i = 0; i < N; i++)
        cin >> lans[i];

    long long min = 1, max = 0;
    for (int len : lans)
        if (max < len)
            max = len;

    int stack;
    long long mid;
    while (min <= max) {
        mid = (min + max) / 2;

        check(&stack, lans, mid);

        if (stack < length)
            max = mid - 1;
        else min = mid + 1;
    }

    cout << max;
}