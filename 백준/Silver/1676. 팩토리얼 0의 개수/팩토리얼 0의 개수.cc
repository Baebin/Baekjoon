#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int five = 0;
    while (N >= 5) {
        if (N % 5 == 0) five++;
        if (N % 25 == 0) five++;
        if (N-- % 125 == 0) five++;
    }

    cout << five;
}