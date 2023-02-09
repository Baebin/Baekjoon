#include <iostream>
#include <vector>
using namespace std;

void check(long long* stack, vector<long long> vec, long long length) {
    *stack = 0;
    for (long long len : vec)
        *stack += len > length ? len - length : 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M;
    cin >> N >> M;

    vector<long long> trees(N);
    for (int i = 0; i < N; i++)
        cin >> trees[i];

    long long min = 0, max = 0;
    for (int len : trees)
        if (max < len)
            max = len;

    long long stack, mid;
    while (min <= max) {
        mid = (min + max) / 2;

        check(&stack, trees, mid);

        if (stack < M)
            max = mid - 1;
        else min = mid + 1;
    }

    cout << max;
}