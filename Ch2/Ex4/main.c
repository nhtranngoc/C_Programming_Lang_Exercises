#include <stdio.h>

void squeeze(char to[] ,char from[]);

int main() {

	char s1[] = "The quick brown fox jumps over the lazy dog. Susan bought a bit of better butter.";
	char s2[] = "ueoaiUEOAI.";

	squeeze(s1, s2);
	printf("%s\n", s1);

	return 0;
}

void squeeze(char to[], char from[]) {
	int lookuptable[256];
	int i, c, j = 0;

	if(!to[0] || !from[0]) {
		return;
	}

	for(i = 0; i < 256; ++i) {
		lookuptable[i] = 0;
	}

	for(i = 0; (c = from[i]); ++i) {
		lookuptable[c] = 1;
	}

	i = 0;
	while(to[i]) {
		if(lookuptable[to[i++]]) {
			to[j] = to[i];
		} else {
			to[++j] = to[i];
		}
	}
	to[j] = '\0';
}