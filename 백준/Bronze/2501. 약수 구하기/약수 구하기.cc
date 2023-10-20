#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        if (N % i)
            continue;
        if (--K)
            continue;
        cout << i;
        return 0;
    }
    cout << 0;
}