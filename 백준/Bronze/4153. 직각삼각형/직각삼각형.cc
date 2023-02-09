#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x, y, z;

	while (true) {
		cin >> x >> y >> z;
		if (x == 0) return 0;

		if (x * x == y * y + z * z
			|| y * y == x * x + z * z
			|| z * z == x * x + y * y) {
				cout << "right\n";
		}
		else {
			cout << "wrong\n";
		}
	}

}