#include <iostream>
using namespace std;

int main() {
	int n, hap = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		hap += i;
	}

	cout << hap;
}