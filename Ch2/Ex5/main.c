#include <stdio.h>

int any(char to[], char from[]);

int main() {
	int index;
	char s1[] = "The quick brown fox jumps over the lazy dog.";
	char s2[] = ".";

	index = any(s1, s2);

	printf("Character index %d\n", index);

	return 0;
}

int any(char to[], char from[]) {
	int lut[256];
	int i, c;

	if(!to[0] || !from[0]) {
		return -1;
	}

	for(i = 0; i < 256; ++i) {
		lut[i] = 0;
	}

	for(i = 0; (c = from[i]); ++i) {
		lut[c] = 1;
	}

	for(i = 0; to[i]; ++i) {
		if(lut[to[i]]) {
			return i;
		}
	}
	return -1;
}