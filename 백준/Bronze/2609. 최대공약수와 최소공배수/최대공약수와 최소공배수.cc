#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b) {
	int c;
	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B;
	cin >> A >> B;

	int _gcd = gcd(A, B);
	cout << _gcd << "\n";
	cout << (A * B)/_gcd;
}