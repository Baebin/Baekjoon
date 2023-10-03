#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string A, B;
    cin >> A >> B;

    int al = A.length(), bl = B.length();
    int Ml = max(al, bl);

    stack<char> st;
    bool roundNumber = false;
    for (register int i = 0; i <= Ml; i++) {
        int a = 0, b = 0;
        if (i < al) a = A[al - (i + 1)] == '1';
        if (i < bl) b = B[bl - (i + 1)] == '1';

        switch (a + b + roundNumber) {
            case 0:
                st.push('0');
                break;
            case 1:
                st.push('1');
                roundNumber = 0;
                break;
            case 2:
                st.push('0');
                roundNumber = 1;
                break;
            case 3:
                st.push('1');
                roundNumber = 1;
                break;
        }
    }
    while (!st.empty() && st.top() == '0') st.pop();
    if (st.empty()) cout << 0;
    else while (!st.empty()) cout << st.top(), st.pop();
}