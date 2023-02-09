#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int tmp = N;
	int min = 1;
	while (tmp > 10) {
		min *= 10;
		tmp /= 10;
	}

	int sum;
	for (int i = min; i < N; i++) {
		tmp = i;
		sum = 0;

		while (tmp > 0) {
			sum += (tmp % 10);
			tmp /= 10;
		}

		if (N == i + sum) {
			cout << i;
			return 0;
		}
	}

	cout << 0;
}