#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int SUM = (N - 1) * 8;
    while (N--) {
        int K;
        cin >> K;
        SUM += K;
    }
    cout << (SUM /24) << " " << (SUM % 24);
}