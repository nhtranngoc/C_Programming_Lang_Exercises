#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[]) {
	int i, c, lastc = 0;

	while((s[0] = c = getch()) == ' ' || c == '\t');

	s[1] = '\0';
	lastc = c;
	if(!isdigit(c) && c != '.' && !isdigit(getch())) {
		printf("%c\n", c);
		return c; //Not a number
	}

	i = 0;
	if(isdigit(c)) {
		while(isdigit(s[++i] = c = getch()));
	}

	if(c == '.') {
		while(isdigit(s[++i] = c = getch()));
	}

	s[i] = '\0';
	if(c != EOF) {
		ungetch(c);
	}

	// printf("%s\n", s);

	return NUMBER;
}