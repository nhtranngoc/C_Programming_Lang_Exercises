//TEST COMMENT

#include <stdio.h>
#include <stdbool.h>

//Removes comments from from a C program
int main() {
	char c, lastc = 0, llastc = 0;
	bool inlineComment = false, blockComment = false;

	/* This should not be printed */

	while((c = getchar()) != EOF) {
		if((!inlineComment) && (c == '/') && (lastc == '/')) {
			inlineComment = true;
			// printf("inline true");
		}

		if((!blockComment) && (c == '*') && (lastc == '/')) {
			blockComment = true;
			// printf("block true");
		}

		if(inlineComment && lastc == '\n') {
			inlineComment = false;
			// printf("inline false");
		}

		if(blockComment && lastc == '/' && llastc == '*') {
			blockComment = false;
			// printf("block false");
		}

		// Filter out comments based on markers
		if((!inlineComment && !blockComment) && lastc != '/') {
			putchar(lastc);
		} 

		// If not a comment, put '/' back
		if((!inlineComment && !blockComment) && lastc == '/' && c != '*' && llastc != '*') {
			putchar('/');
		}

		llastc = lastc;
		lastc = c;
	}
	printf("This should be printed.\n");
	/* This also should not be printed. */
	// Do not print this ever.
	return 0;
}