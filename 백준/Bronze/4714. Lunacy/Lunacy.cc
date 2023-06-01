#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << fixed;
    cout.precision(2);

    double d;
    while (cin >> d && d != -1)
        cout << "Objects weighing " << d << " on Earth will weigh " << (d * 0.167) << " on the moon." << "\n";
}