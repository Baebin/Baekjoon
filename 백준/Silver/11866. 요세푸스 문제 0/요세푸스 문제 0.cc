#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> people(N);
	queue<int> que_result;
	for (int i = 0; i < N; i++) people[i] = i + 1;

	int idx = 0;
	while (!people.empty()) {
		idx = (idx + (K - 1)) % people.size();
		que_result.push(people[idx]);
		people.erase(people.begin() + idx);
	}

	cout << "<";
	while (!que_result.empty()) {
		cout << que_result.front();
		que_result.pop();

		if (!que_result.empty())
			cout << ", ";
	}
	cout << ">";
}