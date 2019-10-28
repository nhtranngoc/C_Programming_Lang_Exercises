#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void itoa_2(int n, char s[], int w);
void reverse(char s[]);

int main() {
	char s[20];

	for(int i = 0; i < 20; ++i) {
		s[i] = '\0';
	}

	for(int i = 0; i <= 100; ++i) {
		itoa_2(i,s,4);
		printf("%s\n", s);
	}


	return 0;
}

void itoa_2(int n, char s[], int w) {
	int i = 0;
	int sign = n;

	do {
		s[i++] = abs(n % 10) + '0';
	} while(n /= 10);

	if(i < w) {
		for(int j = i; j < w; ++j) {
			s[i++] = '0';
		}
	}

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