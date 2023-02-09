#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> map;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string fruit;
    int num;
    while (N--) {
        cin >> fruit >> num;
        map[fruit] += num;
    }

    for (auto data : map) {
        if (data.second == 5) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}