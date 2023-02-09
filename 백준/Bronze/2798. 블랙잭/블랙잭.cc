#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N, M;
	int num[98] = { };

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	int max = 0, tmp;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				tmp = num[i] + num[j] + num[k];
				if (tmp <= M && tmp > max)
					max = tmp;
			}
		}
	}

	cout << max;
}