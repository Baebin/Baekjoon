#include <iostream>
using namespace std;

// f(n) = (f(n - 1) + K - 1) % n + 1

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    int last = 1;
    for (int i = 2; i <= N; i++)
        last = ((last + K - 1) % i) + 1;

    cout << last;
}