#include <iostream>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;

    b -= 45;
    if (b < 0) {
        a--;
        b += 60;
    }

    if (a < 0) a += 24;

    cout << a << " " << b;
}