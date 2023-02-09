#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	string ps;
	int len, left, right;
	for (int i = 0; i < T; i++) {
		cin >> ps;

		len = ps.length();
		left = 0, right = 0;
		
		for (int j = 0; j < len; j++) {
			if (ps[j] == '(')
				left++;
			else right++;

			if (left < right) {
				break;
			}
		}
		if (left == right)
			cout << "YES\n";
		else cout << "NO\n";
	}
}