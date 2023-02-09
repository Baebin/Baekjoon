#include <stdio.h>
#include <string.h>

int main() {
	char grade[3];
	double score = 4.0;
	scanf("%s", &grade);

	if (grade[0] == 'F') {
		printf("0.0");
		return 0;
	}

	score += 'A' - grade[0];
	if (grade[1] == '+') {
		score += 0.3;
	} else if (grade[1] == '-') {
		score -= 0.3;
	}

	printf("%.1lf", score);
	return 0;
}