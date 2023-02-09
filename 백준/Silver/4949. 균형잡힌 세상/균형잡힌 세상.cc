#include <iostream>
#include <string>
#include <stack>
using namespace std;

int check(const char& c) {
    if (c == '(' || c == '[')
        return 1;
    if (c == ')')
        return 2;
    if (c == ']')
        return 3;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string word;
    while (true) {
        getline(cin, word);

        if (word == ".") return 0;

        stack<char> st;
        bool exit = false;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            int _check = check(c);

            if (_check == 1)
                st.push(c);
            else if (_check == 2) {
                if (st.empty() || st.top() == '[') exit = true;
                else st.pop();
            }
            else if (_check == 3) {
                if (st.empty() || st.top() == '(') exit = true;
                else st.pop();
            }
        }

        if (st.empty() && !exit)
            cout << "yes\n";
        else cout << "no\n";
    }
}