#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string notation;
    cin >> notation;

    stack<char> st;
    for (char c : notation) {
        if (c >= 'A' && c <= 'Z') {
            cout << c;
            continue;
        }
        if (c == '(') {
            st.push(c);
            continue;
        }
        if (c == ')') {
            while (st.top() != '(') {
                cout << st.top();
                st.pop();
            }
            st.pop();
            continue;
        }
        if (c == '*' || c == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                cout << st.top();
                st.pop();
            }
        }
        if (c == '+' || c == '-') {
            while (!st.empty() && st.top() != '(') {
                cout << st.top();
                st.pop();
            }
        }
        st.push(c);
    }

    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}