#include <stdio.h>
#include <string.h>

int main() {
	int T, sum, weight;
	char str[80];
	
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%s", &str);

		sum = 0, weight = 0;
		for (int j = 0; j < strlen(str); j++) {
			if (str[j] == 'O') {
				sum++;
				if (j > 0 && str[j - 1] == 'O') {
					weight++;
					sum += weight;
				}
			}
			else {
				weight = 0;
			}
		}

		printf("%d\n", sum);
	}
}