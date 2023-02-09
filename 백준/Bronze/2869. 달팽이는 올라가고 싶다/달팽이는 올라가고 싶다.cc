#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, V;
	cin >> A >> B >> V;

	if (A >= V) {
		cout << 1;
		return 0;
	}

	int day = (V - A) / (A - B) + 1;
	if ((V - A) % (A - B) != 0) day++;

	cout << day;
}