#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void itoa_2(int n, char s[]);
void reverse(char s[]);

int main() {
	char s[20];

	for(int i = 0; i < 20; ++i) {
		s[i] = '\0';
	}

	for(int i = 0; i <= 100; ++i) {
		itoa_2(i,s);
		printf("%s\n", s);
	}


	return 0;
}

void itoa_2(int n, char s[]) {
	int i = 0;
	int sign = n;

	do {
		s[i++] = abs(n % 10) + '0';
	} while(n /= 10);

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