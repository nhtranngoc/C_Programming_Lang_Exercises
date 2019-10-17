#include <stdio.h>

int main() {
	int c;
	int newLineCount = 0, tabCount = 0, blankCount = 0;
	while ((c = getchar()) != EOF) {
		switch(c) {
			case '\n':
			newLineCount++;
			break;
			case '\t':
			tabCount++;
			break;
			case ' ':
			blankCount++;
			break;
		}
	}

	printf("New line count: %d\n", newLineCount);
	printf("Tab count: %d\n", tabCount);
	printf("Blank count: %d\n", blankCount);

	return 0;
}