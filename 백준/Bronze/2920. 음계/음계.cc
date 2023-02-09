#include <stdio.h>

int main() {
	int num[8];

	for (int i = 0; i < 8; i++) {
		scanf("%d", &num[i]);
		if (num[0] == 8) {
			if (i > 0 && num[i-1] < num[i]) {
				printf("mixed");
				return 0;
			}
		}
		else if (num[0] == 1) {
			if (i > 0 && num[i - 1] > num[i]) {
				printf("mixed");
				return 0;
			}
		}
		else {
			printf("mixed");
			return 0;
		}
	}

	if (num[0] == 8) {
		printf("descending");
	} else {
		printf("ascending");
	}
}