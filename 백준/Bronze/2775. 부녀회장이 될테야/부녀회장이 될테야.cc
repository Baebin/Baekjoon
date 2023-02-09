#include <iostream>
using namespace std;

int getPeople(int a, int b) {
	if (b == 1)
		return 1;
	if (a == 0)
		return b;

	return getPeople(a - 1, b) + getPeople(a, b - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int k, n;
	for (int i = 0; i < T; i++) {
		cin >> k >> n;
		cout << getPeople(k, n) << "\n";
	}
}