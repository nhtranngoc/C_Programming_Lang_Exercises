#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
#define SIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int c);
int getfloat(double *pn);

int main() {
	int n;
	double array[SIZE];

	for(n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++);

	for(int i = 0; i < SIZE; ++i) {
		printf("%g ", array[i]);
	}

	return 0;
}

int getch() {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if(bufp >= BUFSIZE) {
		printf("ungetch: too many characters\n");
	} else {
		buf[bufp++] = c;
	}
}

int getfloat(double *pn) {
	int c;
	double power, sign;

	while(isspace(c = getch()));

	if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);
		return 0; // Not a number
	}

	sign = (c == '-') ? -1.0 : 1.0;
	if(c == '+' || c == '-') {
		c = getch();

		if(!isdigit(c)) {
			ungetch(sign == -1.0 ? '-' : '+');
			return 0;
		}
	}

	for(*pn = 0.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
	}

	if(c == '.') {
		c = getch();
	}

	for(power = 1.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
		power *= 10.0;
	}

	*pn *= sign / power;

	if(c != EOF) {
		ungetch(c);
	}

	return c;
}