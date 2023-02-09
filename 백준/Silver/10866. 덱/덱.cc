#include <iostream>
#include <deque>
using namespace std;

deque<int> que;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	string cmd; int val;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		
		if (cmd.compare("push_front") == 0) {
			cin >> val;
			que.push_front(val);
		}
		else if (cmd.compare("push_back") == 0) {
			cin >> val;
			que.push_back(val);
		}
		else if (cmd.compare("pop_front") == 0) {
			if (que.empty()) {
				cout << "-1\n";
				continue;
			}
			val = que.front();
			que.pop_front();

			cout << val << "\n";
		}
		else if (cmd.compare("pop_back") == 0) {
			if (que.empty()) {
				cout << "-1\n";
				continue;
			}
			val = que.back();
			que.pop_back();

			cout << val << "\n";
		}
		else if (cmd.compare("size") == 0)
			cout << que.size() << "\n";
		else if (cmd.compare("empty") == 0)
			cout << que.empty() << "\n";
		else {
			if (que.empty()) {
				cout << "-1\n";
				continue;
			}
			if (cmd.compare("front") == 0)
				cout << que.front() << "\n";
			else cout << que.back() << "\n";
		}
	}
}