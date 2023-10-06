#include <iostream>
using namespace std;

int main() {
	string N;
	cin >> N;

    int ans = 0;
    for (const char& c : N) {
		ans *= 16;
		if (c >= 'A' && c <= 'F')
			ans += 10 + (c - 'A');
		else ans += (c - '0');
	}
	cout << ans;
}