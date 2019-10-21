#include <stdio.h>

#define MAXLINE 1000

void reverse(char s[]);
int getline(char s[]);

int main() {
	char input[MAXLINE];

	while(getline(input) > 0) {
		reverse(input);
		printf("%s\n", input);
	}

	return 0;
}

/* Your average getline() function. Returns index (length) of string */
int getline(char s[]) {
	int c, i;
	for(i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}

	if(c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\n';

	return i;
}

/* Reverse a given string */
void reverse(char s[]) {
	int i, j;
	char buffer;

	//Before the advent of sizeof
	for(i = 0; s[i] != '\0'; ++i) {
	}
	--i;

	for(j = 0 ; j < i; ++j) {
		buffer = s[j];
		s[j] = s[i];
		s[i] = buffer;
		--i;
	}
}