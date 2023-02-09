#include <stdio.h>
#include <string.h>

int main() {
	int temp;
	char word[101];
	int alphabet[26] = {};

	scanf("%s", word);
	for (int i = 1; i <= strlen(word); i++) {
		temp = word[i - 1] - 97;
		if (alphabet[temp] == 0) {
			alphabet[temp] = i;
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", alphabet[i] - 1);
	}
}