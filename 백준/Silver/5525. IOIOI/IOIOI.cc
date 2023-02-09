#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
using namespace std;

#define IOI (N * 2 + 1)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string str;
    cin >> str;

    int stack = 0;
    for (int i = 0; i < M - IOI; i++) {
        int cnt = 0;
        bool isI = false;
        for (int j = i; j < i + IOI; j++) {
            if (isI = !isI) {
                if (str[j] == 'I')
                    cnt++;
            }
            else if (str[j] == 'O')
                cnt++;
        }

        if (cnt == IOI)
            stack++;
    }

    cout << stack;
}