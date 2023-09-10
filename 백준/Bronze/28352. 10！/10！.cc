#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long int fibo = 1;
    while (N--)
        fibo *= N + 1;
    cout << (fibo / (7 * 24 * 60 * 60));
}