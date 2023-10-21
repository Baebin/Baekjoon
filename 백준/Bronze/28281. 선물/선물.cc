#include <iostream>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    int ans = 2e9;
    int* arr = new int[N];
    for (register int i = 0; i < N; i++)
        cin >> arr[i], (i ? ans = min(ans, arr[i - 1] + arr[i]) : 0);
    cout << ans * X;
}