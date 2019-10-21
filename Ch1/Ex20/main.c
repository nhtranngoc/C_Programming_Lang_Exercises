#include <stdio.h>

#define TABSTOPS 8 //Each tab stop is 8 column.

void addSpace(int j);

int main() {
	int c;
	int i = 0; // Column counter
	while((c = getchar()) != EOF) {
		//Reset col counter if there's a new line.
		if (c == '\n') {
			i = 0;
		}

		if(c == '\t') {
			//Replace this with spaces;
			if((i % TABSTOPS) == 0) {
				addSpace(8);
			} else addSpace(TABSTOPS - (i % TABSTOPS));
		}

		putchar(c);
		++i;


	}

	return 0;
}

void addSpace(int j) {
	for(int i = 0; i < j; ++i) {
		putchar(' ');
	}
}