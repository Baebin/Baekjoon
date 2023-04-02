#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void print(stack<char> &st) {
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    stack<char> st;
    while (true) {
        getline(cin, str);
        if (str == "#")
            break;
        for (char c: str) {
            if (c == ' ') {
                print(st);
                cout << " ";
            } else st.push(c);
        }
        print(st);
        cout << "\n";
    }
}