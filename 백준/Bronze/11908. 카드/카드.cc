#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int sum = 0, M = 0;
    while (N--) {
        int C;
        cin >> C;
        sum += C;
        M = max(M, C);
    }
    cout << (sum - M);
}