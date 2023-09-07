#include <iostream>
using namespace std;

// Structure
typedef long long ll;

int findIdx(const string& color) {
    const string colors[10] = {
            "black", "brown", "red",
            "orange", "yellow", "green",
            "blue", "violet", "grey",
            "white"
    };
    for (register int i = 0; i < 10; i++)
        if (color == colors[i])
            return i;
    return 0;
}

int getAdd(const string& color) {
    return findIdx(color);
}

int getMul(const string& color) {
    int mul = 1;
    int cnt = findIdx(color);
    while (cnt--)
        mul *= 10;
    return mul;
}

int main() {
    string c1, c2, c3;
    cin >> c1 >> c2 >> c3;

    ll a1 = getAdd(c1);
    ll a2 = getAdd(c2);

    do a1 = (a1 * 10) + a2 % 10;
    while (a2 /= 10);
    cout << (a1 * getMul(c3));
}