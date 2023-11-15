#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;

        int sum = 0;
        vector<bool> check(26);
        for (const char& c : S)
            check[c - 'A'] = true;
        for (int i = 0; i < 26; i++)
            if (!check[i])
                sum += i + 'A';
        cout << sum << '\n';
    }
}