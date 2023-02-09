#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int num;
    stack<int> st;
    for (int i = 0; i < N; i++) {
        cin >> num;

        if (num != 0)
            st.push(num);
        else if (!st.empty())
            st.pop();
    }

    int sum = 0;
    while (!st.empty()) {
        sum += st.top();
        st.pop();
    }

    cout << sum;
}