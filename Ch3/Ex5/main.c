#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[]);
void itob(int n, char s[], int b);

int main() {
	char s[20];

	for(int i = 0; i < 20; ++i) {
		s[i] = '\0';
	}

	for(int i = 0; i <= 100; ++i) {
		itob(i,s,12);
		printf("%s\n",s);
	}

	return 0;
}

void itob(int n, char s[], int b) {
	int i = 0;
	int sign = n;

	do {
		if(abs(n%b) > 9) {
			s[i++] = abs(n % b) + '0' + 7;
		} else {
			s[i++] = abs(n % b) + '0';
		}
	} while(n /= b);

	if(sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {
	int c, i, j;

	for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

}