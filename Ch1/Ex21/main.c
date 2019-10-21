#include <stdio.h>

#define TABSTOPS 8

int main() {
	int c, i = 0;
	
	while((c = getchar()) != EOF) {
		if(c == ' ') {
			++i;
		} else {
			int tabCount = i / TABSTOPS;
			int spaceCount = i % TABSTOPS;

			for(int k = 0; k < tabCount; ++k) {
				putchar('\t');

			}

			for(int j = 0; j < spaceCount; ++j) {
				putchar(' ');
			}

			putchar(c);
			i = 0;
		} 
	}

	return 0;
}