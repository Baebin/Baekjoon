#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string N;
	int len, flag;
	while (true) {
		cin >> N;
		if (N.compare("0") == 0) return 0;

		flag = true;
		len = N.length();

		for (int i = 0; i < len/2; i++) {
			if (N[i] != N[(len - i) - 1]) {
				flag = false;
				cout << "no\n";
				break;
			}
		}
		
		if (flag) cout << "yes\n";
	}
}