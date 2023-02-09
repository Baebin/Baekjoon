#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 500000

vector<bool> isBroken(10);

bool hasBrokenKey(string num) {
    int len = num.length();
    for (int i = 0; i < len; i++)
        if (isBroken[num[i] - '0'])
            return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    int M;
    cin >> M;

    int tmp;
    while (M--) {
        cin >> tmp;
        isBroken[tmp] = true;
    }

    // Start Channel: 100
    int cnt = abs(num - 100);

    for (int i = 0; i <= MAX * 2; i++) {
        string key = to_string(i);
        if (hasBrokenKey(key))
            continue;
        if (cnt > abs(num - i) + key.length())
            cnt = abs(num - i) + key.length();
    }

    cout << cnt;
}