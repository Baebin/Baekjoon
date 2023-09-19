#include <iostream>
using namespace std;
 
int main(void) {
    int m = 2e9, sum = 0;
	for (int i = 0; i < 7; i++) {
        int n;
        cin >> n;
		if (n % 2 == 0)
            continue;
        sum += n;
        m = min(m, n);
	}
	if (sum == 0) cout << -1;
	else cout << sum << "\n" << m;
}