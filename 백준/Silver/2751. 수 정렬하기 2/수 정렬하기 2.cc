#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int tmp;
	vector<int> num(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	sort(num.begin(), num.end());
	for (int n : num)
		cout << n << "\n";
}