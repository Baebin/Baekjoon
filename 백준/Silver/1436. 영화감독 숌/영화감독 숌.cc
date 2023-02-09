#include <iostream>
#include <vector>
using namespace std;

int getSix(int num) {
	int cnt = 0;
	int max = 0;

	while (num > 0) {
		if (num % 10 == 6) {
			cnt++;
			if (cnt > max) max = cnt;
		} else cnt = 0;
		num /= 10;
	}
	return max;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int num = 666;
	int cnt = 0;
	while (true) {
		if (getSix(num++) >= 3)
			cnt++;
		if (cnt == N) {
			cout << num - 1;
			return 0;
		}
	}
}