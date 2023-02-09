#include <stdio.h>
#include <string.h>

int main() {
	int tmp, total = 0;
	int remain[42] = { };
	for (int i = 0; i < 10; i++) {
		scanf("%d", &tmp);

		tmp %= 42;
		if (remain[tmp] == 0) {
			remain[tmp]++;
			total++;
		}
	}
	printf("%d", total);
}