#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 1000

int getline(char *s, int lim);
int atoi2(char *s);
void itoa2(int n, char *s);
void reverse(char *s);

int main() {
	int len;
	char line[MAXLINE];

	// while((len = getline(line, MAXLINE)) == 1) {
	// 	printf("%s\n", line);
	// }

	// while(len = getline(line, MAXLINE) > 0) {
	// 	printf("%d\n", atoi2(line));
	// }
	
	int n = -1234;
	char s[100];
	itoa2(n,s);
	printf("%s\n", s);
	
	char s2[] = "-123456";
	reverse(s2);
	printf("%s\n", s2);

	return 0;
}

void itoa2(int n, char *s) {
	int sign;

	if((sign = n) < 0) {
		n = -n;
	}

	do {
		*s++ = n % 10 + '0';
	} while((n/=10) > 0);

	if(sign < 0) {
		*s++ = '-';
	}
	*s-- = '\0';

	reverse(s);
}

void reverse(char *s) {
	char *p_first, *p_last, tmp;
	int len = strlen(s);
	p_first = p_last = s;

	while(*++p_last);
	*--p_last;

	for(int i = 0; i < len/2; i++) {
		tmp = *p_first;
		*p_first++ = *p_last;
		*p_last-- = tmp;
	}
}

int atoi2(char *s) {
	int sign, n = 0;
	while(isspace(*++s));

	sign = (*s == '-') ? -1 : 1;

	if(*s == '+' || *s == '-') {
		*s++;
	}

	while(isdigit(*s)){
		n = 10*n + (*s - '0');
		*s++;
	}

	return sign * n;

}

int getline(char *s, int lim) {
	int c, i=0;
	while(i < lim-1 && (c=getchar()) != EOF && c != '\n') {
		i++;
		*++s = c;
	}

	if(c == '\n') {
		*++s = c;
	}

	*s = '\0';

	return i;
}