#include <stdio.h>

int lower(int c);

int main() {
	char input[] = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.";

	for(int i=0; input[i] != '\0'; ++i) {
		putchar(lower(input[i]));
	}

	return 0;
}

int lower(int c) {
	return (c >='A' && c <= 'Z') ? c + 'a' - 'A' : c;
}