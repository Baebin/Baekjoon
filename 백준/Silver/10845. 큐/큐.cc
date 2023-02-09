#include <iostream>
#include <queue>
using namespace std;

queue<int> que;

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
			que.push(val);
		}
		else if (cmd.compare("pop") == 0) {
			if (que.empty()) {
				cout << "-1\n";
				continue;
			}
			val = que.front();
			que.pop();

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