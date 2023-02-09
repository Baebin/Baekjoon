#include <stdio.h>
#include <string.h>

int main() {
	char word;

	while (scanf("%c", &word) != EOF) {
		printf("%c", word);
	}
}