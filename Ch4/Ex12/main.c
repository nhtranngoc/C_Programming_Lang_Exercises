#include <stdio.h> 
#define MAX_CHAR 100

void itoa2(int n, char s[]);

int main() {
	char s[MAX_CHAR];
	itoa2(3145, s);
	printf("%s\n", s);
	itoa2(5312, s);
	printf("%s\n", s);

	return 0;
}

void itoa2(int n, char s[]) {
	static int  i = 0;
	if(n < 0) {
		s[0] = '-';
		n = -n;
	}

	if(n/10) {
		itoa2(n/10, s);
	} else {
		i = 0;
	}
	s[i++] = n % 10 + '0';
}