#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	unordered_map<int, int> num(N);

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		num.insert({ tmp, 1 });
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		cout << (num.count(tmp)) << "\n";
	}
}