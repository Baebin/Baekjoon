#include <stdio.h>

int main(void) {
	int n, hap = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		hap += i;
	}

	printf("%d", hap);

	return 0;
}