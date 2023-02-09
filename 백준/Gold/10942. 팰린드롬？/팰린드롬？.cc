#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> vec(N);
	vector<vector<bool>> dp(N, vector<bool>(N));

	for (int i = 0; i < N; i++) {
		cin >> vec[i];
		dp[i][i] = true;
		if (i > 0 && vec[i] == vec[i - 1])
			dp[i - 1][i] = true;
	}
	for (int i = N - 2; i >= 0; i--)
		for (int j = i + 2; j < N; j++)
			if (vec[i] == vec[j] && dp[i + 1][j - 1])
				dp[i][j] = true;
		
	int M;
	cin >> M;
	while (M--) {
		int S, E;
		cin >> S >> E;
		cout << dp[S - 1][E - 1] << "\n";
	}
}