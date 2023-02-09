#include <iostream>
#include <vector>
using namespace std;

#define MAX 20

vector<bool> S(MAX + 1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    string cmd; int x;
    while (M--) {
        cin >> cmd;

        if (cmd == "empty")
            fill(S.begin(), S.end(), false);
        else if (cmd == "all")
            for (int i = 1; i <= MAX; i++)
                S[i] = true;
        else {
            cin >> x;

            if (cmd == "add")
                S[x] = true;
            else if (cmd == "remove")
                S[x] = false;
            else if (cmd == "check")
                cout << S[x] << "\n";
            else S[x] = !S[x];
        }
    }
}