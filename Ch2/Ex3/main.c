#include <stdio.h>

int htoi(char s[]);
int lower(int c);

int main() {
	char s[] = "0xFF"; // Should return 255
	char s1[] = "0x00"; // Should return 0
	char s2[] = "0xbaby"; // Should return 2987 since it evaluates 'bab' 

	printf("%d\n", htoi(s));
	printf("%d\n", htoi(s1));
	printf("%d\n", htoi(s2));

	return 0;
}

// Converts hex string to int 
// Takes in Ox or OX
int htoi(char s[]) {
	int n = 0, i;

	// Check for validity
	if(s[0] != '0' || lower(s[1]) != 'x') {
		return -1;
	}

	for(i = 2; (s[i] >= '0' && s[i] <= '9') || (lower(s[i]) >= 'a' && lower(s[i]) <= 'f'); ++i) {
		if(s[i] >= '0' && s[i] <= '9') {
			n = 16 * n + s[i] - '0';
		}

		if(lower(s[i]) >= 'a' && lower(s[i]) <= 'f') {
			n = 16 * n + lower(s[i]) - 'a' + 10;
		}
	}
	return n;
}

int lower(int c) {
	if(c >= 'A' && c <= 'Z') {
		return c + 'a' - 'A';
	} else return c;
}