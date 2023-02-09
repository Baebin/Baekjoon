#include <iostream>
#include <queue>
#include <stack>
using namespace std;

stack<int> st;
queue<char> que;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int pivot;
    int max = 0, is_end = false;
    for (int i = 0; i < N; i++) {
        cin >> pivot;

        if (is_end) continue;
        if (pivot > max) {
            while (pivot > max) {
                st.push(++max);
                que.push('+');
            }
        } else if (st.top() != pivot)
            is_end = true;

        st.pop();
        que.push('-');
    }

    if (is_end) {
        cout << "NO";
        return 0;
    }
    while (!que.empty()) {
        cout << que.front() << "\n";
        que.pop();
    }
}