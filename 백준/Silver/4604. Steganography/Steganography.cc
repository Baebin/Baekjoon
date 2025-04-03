#include <iostream>
#include <string>
using namespace std;

char decode(int code) {
    switch (code) {
    case 0:
        return ' ';
    case 27:
        return '\'';
    case 28:
        return ',';
    case 29:
        return '-';
    case 30:
        return '.';
    case 31:
        return '?';
    default:
        return ('A' + (code - 1));
    }
}

void init(int& cnt, int& idx, int& code) {
    cnt = code = 0;
    idx = 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int cnt, idx, code;
    init(cnt, idx, code);

    string line;
    while (getline(cin, line) && line != "#") {
        if (line == "*") {
            if (code)
                cout << decode(code);
            cout << '\n';
            init(cnt, idx, code);
            continue;
        }
        for (char c : line) {
            if (c == ' ') {
                cnt++;
                continue;
            }
            if (cnt) {
                if (cnt % 2 == 0)
                    code |= (1 << idx);
                if (idx-- == 0)
                    cout << decode(code), init(cnt, idx, code);
            }
            cnt = 0;
        }
    }
}
