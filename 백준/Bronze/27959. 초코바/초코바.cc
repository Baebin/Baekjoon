#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    cout << ((M - 100 * N <= 0) ? "Yes" : "No");
}