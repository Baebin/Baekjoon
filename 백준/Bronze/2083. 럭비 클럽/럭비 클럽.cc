#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string name;
    int age, weight;

    while (true) {
        cin >> name >> age >> weight;
        if (name == "#")
            return 0;
        cout << name;
        if (age > 17 || weight >= 80)
            cout << " Senior\n";
        else cout << " Junior\n";
    }
}