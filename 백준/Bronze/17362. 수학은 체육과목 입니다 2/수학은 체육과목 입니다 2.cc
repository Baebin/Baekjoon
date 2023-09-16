#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    N %= 8;
    if (N == 0) cout << 2;
    else if (N <= 5) cout <<N;
    else cout << (10 - N);
}