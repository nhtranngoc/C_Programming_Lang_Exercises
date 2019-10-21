#include <stdio.h>
#include <stdbool.h>

#define MAXLINE 20 // Max column before rollover
#define TABSTOPS 8

char line[MAXLINE];	//Buffer
bool inWord = false;
int i = 0;

void printLine(char s[]);

int main() {
	int c, lastBlank;
	char currentWord[MAXLINE];

	while((c = getchar()) != EOF) {
		line[i] = c; //Move pointer to new position
		++i;

		if(c == ' ' || c == '\t' || c == '\n') {
			inWord = false;
			lastBlank = i;
		} else {
			inWord = true;
			currentWord[i] = c;
		}

		// check if in word
		// if inword && over the line?
		// then backtrack to last whitespace, \n then print the rest on new line

		if(i > MAXLINE) {
			if(inWord) {
				i = lastBlank;
			}

			printLine(line);
			i = 0;
		}

		//End input
		if(c == '\n') {
			printLine(line);
			i = 0;
		}
	}

	return 0;
}

void printLine(char s[]) {
	for(int j = 0; j < i; ++j) {
		putchar(line[j]);
	} 
	if(i > 0) {
		putchar('\n');
	}
}