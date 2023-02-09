#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str, boom;
    cin >> str >> boom;

    int str_len = str.length();
    int boom_size = boom.length();

    vector<char> vec;
    for (int i = 0; i < str_len; i++) {
        vec.push_back(str[i]);

        int size = vec.size();
        if (size >= boom_size) {
            bool isExploded = true;

            int idx = boom_size;
            for (int i = size - 1; i >= 0; i--) {
                if (vec[i] != boom[--idx]) {
                    isExploded = false;
                    break;
                }
                if (idx == 0)
                    break;
            }
            if (isExploded)
                for (int i = 0; i < boom_size; i++)
                    vec.pop_back();
        }
    }

    if (vec.empty())
        cout << "FRULA";
    else for (char c : vec)
        cout << c;
}