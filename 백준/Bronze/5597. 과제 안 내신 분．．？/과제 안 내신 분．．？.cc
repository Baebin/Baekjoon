#include <stdio.h>

int main() {
	int student, is_okay[30] = {};

	for (int i = 0; i < 28; i++) {
		scanf("%d", &student);
		is_okay[student - 1] = 1;
	}

	for (int i = 1; i <= 30; i++) {
		if (!is_okay[i-1]) {
			printf("%d\n", i);
		}
	}
}