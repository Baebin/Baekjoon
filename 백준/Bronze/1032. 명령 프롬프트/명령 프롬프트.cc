#include <stdio.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);

	char cmd[50], temp[50];
	scanf("%s", &cmd);
	for (int i = 1; i < N; i++) {
		scanf("%s", &temp);
		for (int j = 0; j < strlen(cmd); j++) {
			if (cmd[j] != temp[j]) {
				cmd[j] = '?';
			}
		}
	}

	printf("%s", cmd);
}