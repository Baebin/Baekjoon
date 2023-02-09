#include <iostream>
#include <deque>
using namespace std;

deque<int> people;

void move(int cnt, int isReverse) {
	for (int i = 1; i < cnt; i++) {
		// Left
		if (isReverse == 1) {
			people.push_front(people.back());
			people.pop_back();
		}
		else {
			people.push_back(people.front());
			people.pop_front();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K, M;
	cin >> N >> K >> M;

	for (int i = 1; i <= N; i++) people.push_back(i);

	int idx = 0, cnt = 0, isReverse = -1;
	while (!people.empty()) {
		move(K, isReverse);

		if (isReverse == 1) {
			cout << people.back() << "\n";
			people.pop_back();
		}
		else {
			cout << people.front() << "\n";
			people.pop_front();
		}

		if (++cnt == M) {
			cnt = 0;
			isReverse *= -1;
		}
	}
}