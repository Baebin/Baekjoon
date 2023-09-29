#include <iostream>
using namespace std;

int main() {
    int N, sum = 0;
    while (cin >> N && N != -1)
        sum += N;
    cout << sum;
}