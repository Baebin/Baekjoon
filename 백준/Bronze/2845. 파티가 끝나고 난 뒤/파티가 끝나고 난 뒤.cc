#include <iostream>
#include <vector>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    int W = A * B;
    cout << (a - W) << " " << (b - W) << " " << (c - W) << " " << (d - W) << " " << (e - W);
}