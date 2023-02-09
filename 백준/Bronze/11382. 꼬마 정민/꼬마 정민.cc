#include <stdio.h>

int main() {
	long long num, sum = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%lld", &num);
		sum += num;
	}
	printf("%lld", sum);
}