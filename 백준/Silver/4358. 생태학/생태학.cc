#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int total = 0;
    map<string, int> m;

    string _type;
    while (getline(cin, _type)) {
        m[_type]++;
        total++;
    }

    cout << fixed;
    cout.precision(4);
    for (auto tree : m)
        cout << tree.first << " " << (100 * tree.second) / (float)total << "\n";
}