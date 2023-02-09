#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	char **board = new char*[N];
	for (int i = 0; i < N; i++) {
		board[i] = new char[M];

		for (int j = 0; j < M; j++)
			cin >> board[i][j];
	}

	int minimum = 64;
	int is_white;
	int stack, stack_2;

	for (int row = 0; row + 8 <= N; row++) {
		for (int column = 0; column + 8 <= M; column++) {
			stack = 0, stack_2 = 0;

			for (int i = row; i < row + 8; i++) {
				for (int j = column; j < column + 8; j++) {
					// BWBWBW
					// WBWBWB
					// BWBWBW
					// WBWBWB

					is_white = ((i - row) + (j - column)) % 2;
					if (board[i][j] == 'B') {
						if (is_white)
							stack++;
					} else if (!is_white)
						stack++;

					// WBWBWB
					// BWBWBW
					// WBWBWB
					// BWBWBW

					is_white = !is_white;
					if (board[i][j] == 'B') {
						if (is_white)
							stack_2++;
					} else if (!is_white)
						stack_2++;
				}
			}

			minimum = min(
				minimum,
				min(stack, stack_2)
			);
		}
	}

	cout << minimum;
}