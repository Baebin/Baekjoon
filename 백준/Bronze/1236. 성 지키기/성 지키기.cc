#include <stdio.h>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	int R = N, C = M;
	char guard[50][50] = { };
	for (int i = 0; i < N; i++) {
		scanf("%s", guard[i]);

		// Column Search
		for (int j = 0; j < M; j++) {
			if (guard[i][j] == 'X') {
				R--;
				break;
			}
		}
	}
	for (int i = 0; i < M; i++) {
		// Row Search
		for (int j = 0; j < N; j++) {
			if (guard[j][i] == 'X') {
				C--;
				break;
			}
		}
	}

	printf("%d", R > C ? R : C);
}