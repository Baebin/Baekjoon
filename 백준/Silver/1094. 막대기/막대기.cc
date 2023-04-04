#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int cnt = 0;
    int tmp = 64;
    while (N && tmp) {
        if (N >= tmp) {
            N -= tmp;
            cnt++;
        }
        tmp /= 2;
    }
    cout << cnt;
}