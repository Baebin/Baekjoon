#include <stdio.h>

int main() {
	int loc, max = 0, temp;

	for (int i = 0; i < 9; i++) {
		scanf("%d", &temp);
		if (temp > max) {
			max = temp;
			loc = i + 1;
		}
	}

	printf("%d\n%d", max, loc);
}