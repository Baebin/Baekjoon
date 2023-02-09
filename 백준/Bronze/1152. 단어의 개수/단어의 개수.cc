#include <stdio.h>
#include <string.h>

int main() {
	int stack = 0, len;
	char word[1000001];
	
	scanf("%[^\n]s", &word);

	len = strlen(word);
	if (word[0] != ' ') {
		stack++;
	}

	for (int i = 1; i < len; i++) {
		if (word[i - 1] == ' ' && word[i] != ' ') stack++;
	}
	printf("%d", stack);
}