#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> vec(N);
    while (N--) {
        string str;
        cin >> str;

        for (int i = M - 1; i >= 0; i--)
            cout << str[i];
        cout << "\n";
    }
}