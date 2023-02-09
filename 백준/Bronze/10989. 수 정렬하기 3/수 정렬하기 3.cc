#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10000

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> num(MAX + 1, 0);

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		num[tmp]++;
	}

	for (int i = 0; i < MAX + 1; i++)
		if (num[i] != 0)
			for (int j = 0; j < num[i]; j++)
				cout << i << "\n";
}