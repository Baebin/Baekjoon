#include <iostream>
using namespace std;

#define R 31
#define M 1234567891

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string str;

	cin >> N >> str;
	
	int hash = 0;
	int i = 0, r = 1;
	for (int i = 0; i < N; i++) {
		hash += ((str[i] - 'a') + 1) * r;
		r *= R;
	}

	cout << hash % M;
}