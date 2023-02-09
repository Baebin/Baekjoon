#include <stdio.h>
#include <string.h>

int main() {
	int N, temp, max = 0;
	float avg = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		avg += temp*100;
		
		if (temp > max) max = temp;
	}
	avg /= max*N;
	printf("%f", avg);
}