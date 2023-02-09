#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000
vector<bool> primes(MAX + 1, false);

void checkPrime() {
	// Check: Reverse
	// Prime -> False
	// Multiple -> True

	primes[0] = true;
	primes[1] = true;

	for (int i = 2; i <= MAX; i++) {
		if (primes[i]) continue;

		for (int j = 2 * i; j <= MAX; j += i)
			primes[j] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	checkPrime();
	
	int cnt = 0, tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (!primes[tmp])
			cnt++;
	}
	cout << cnt;
}