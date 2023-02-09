#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long k;
    long long a, b, c, d;

    cin >> k;
    cin >> a >> b >> c >> d;

    long long tmp = a * k + b;
    if (tmp != c * k + d)
        cout << "No";
    else cout << "Yes " << tmp;
}