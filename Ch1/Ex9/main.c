#include <stdio.h>
#include <string.h>

int main() {
	int c;
	int blankCount = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			blankCount++;
		} else blankCount = 0;

		if(blankCount <= 1) {
			putchar(c);
		}
	}
	return 0;
}