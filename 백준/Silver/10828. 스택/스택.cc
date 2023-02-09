#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	string cmd; int val;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		
		if (cmd.compare("push") == 0) {
			cin >> val;
			st.push(val);
		}
		else if (cmd.compare("pop") == 0) {
			if (st.empty()) {
				cout << "-1\n";
				continue;
			}
			val = st.top();
			st.pop();

			cout << val << "\n";
		}
		else if (cmd.compare("size") == 0)
			cout << st.size() << "\n";
		else if (cmd.compare("empty") == 0)
			cout << st.empty() << "\n";
		else
			if (st.empty())
				cout << "-1\n";
			else cout << st.top() << "\n";
	}
}