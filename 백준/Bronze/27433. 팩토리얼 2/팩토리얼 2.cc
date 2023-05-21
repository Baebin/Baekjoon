#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    if (N == 0) {
        cout << 1;
        return 0;
    }

    long long an = 1;
    for (int i = 2; i <= N; i++)
        an *= i;
    cout << an;
}