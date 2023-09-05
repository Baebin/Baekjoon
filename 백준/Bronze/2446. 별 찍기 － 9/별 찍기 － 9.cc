#include <iostream>
using namespace std;

void print(const int& N, const int& i) {
    for (int j = 0; j < i; j++)
        cout << " ";
    for (int j = 0; j < 2 * (N - i) - 1; j++)
        cout << "*";
    cout << '\n';
}

int main() {
    int N;
    cin >> N;

    for (register int i = 0; i < N; i++)
        print(N, i);
    for (register int i = N - 2; i >= 0; i--)
        print(N, i);
}