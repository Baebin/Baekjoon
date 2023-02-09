#include <stdio.h>
#include <string.h>

int main() {
	int alphabet[26] = { };
	char word[1000001];

	int max = 0, index;
	char result = '?';

	scanf("%s", word);
	int len = strlen(word);
	for (int i = 0; i < len; i++) {
		index = word[i];
		if (index >= 'a')
			index -= 'a';
		else
			index -= 'A';

		alphabet[index]++;
		if (alphabet[index] > max) {
			max = alphabet[index];
			result = index + 'A';
		} else if (alphabet[index] == max && result != '?')
			result = '?';
	}

	printf("%c", result);
}