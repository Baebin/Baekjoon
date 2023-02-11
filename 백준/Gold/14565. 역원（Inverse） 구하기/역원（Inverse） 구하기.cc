#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 

#include <iostream>
using namespace std;

// Structure
typedef long long ll;

ll exGCD(const ll& A, const ll& B) {
	ll a = A, b = B;
	ll x1 = 1, x2 = 0;
	while (b) {
		ll quotient = a / b;
		ll tmp = a % b;
		a = b;
		b = tmp;

		tmp = x1 - quotient * x2;
		x1 = x2, x2 = tmp;
	}

	// 서로소 X
	if (a != 1)
		return -1;
	while (x1 < 0)
		x1 += B;
	return x1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, A;
	cin >> N >> A;

	// 덧셈역
	cout << (N - A) << " ";

	// 곱셈역
	cout << exGCD(A, N);
}