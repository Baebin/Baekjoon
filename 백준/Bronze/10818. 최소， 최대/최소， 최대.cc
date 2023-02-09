#include <stdio.h>
#include <string.h>

int main() {
	int N, temp;
	int min = 1000000, max = -1000000;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		if (temp < min) min = temp;
		if (temp > max) max = temp;
	}

	printf("%d %d", min, max);
}