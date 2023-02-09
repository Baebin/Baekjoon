#include <stdio.h>
#include <string.h>

int main() {
	int multiply = 1;
	int tmp;

	for (int i = 0; i < 3; i++) {
		scanf("%d", &tmp);
		multiply *= tmp;
	}

	int total[10] = { };
	while (multiply > 0) {
		tmp = multiply % 10;

		total[tmp]++;
		multiply /= 10;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d\n", total[i]);
	}
}