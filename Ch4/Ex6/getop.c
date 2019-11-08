#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[]) {
	int i, c, lastc = 0;

	while((s[0] = c = getch()) == ' ' || c == '\t');

	s[1] = '\0';
	lastc = c;
	if(!isdigit(c) && c != '.' && c != '-' && (!isalpha(c))) {
		return c; //Not a number
	}

	i = 0;

	if(c == '-') {
		char get_tmp = getch();
		if(isdigit(get_tmp)) { //Peek to check if negative number
			ungetch(get_tmp);	// Put dat shit back
			s[++i] = c = getch(); // Grab it for real
		} else {
			return c;
		}
	}

	if(isalpha(c)) {
		i = 0;
		while(isalpha(s[i++] = c)) {
			 c = getch();
		}
		s[i-1] = '\0';

		if(c != EOF) {
			ungetch(c);
		}

		return VAR;
	}

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

int assign(char c, double v) {
	printf("%c\n ", c);
	printf("Assigned %g to %d \n", v, c-'a');
	var[c-'a'] = v;


	for(int i = 0; i < MAX_VAR; ++i) {
		printf("%g ", var[i]);
	}
	printf("\n");
	return 1;
}

void retrieve(char c) {
	push(var[c-'a']);
}