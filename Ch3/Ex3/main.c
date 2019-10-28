#include <stdio.h>
#define MAXCHAR 1000

void expand(char s1[], char s2[]);

int main() {
	char s1[] = "-a This will expand from -  a-z";
	char s2[MAXCHAR];

	expand(s1, s2);
	printf("%s\n", s2);

	return 0;
}

void expand(char s1[], char s2[]) {
	int i, j = 0;
	for(i = 0; s1[i] != '\0'; ++i) {
		if(i != 0 && s1[i] == '-' && (s1[i-1] < s1[i+1])) {
			int dist = s1[i+1] - s1[i-1];
			for(int k = 1; k < dist; ++k) {
				s2[j] = s2[i-1] + k;
				++j;
			}
		} else {
			s2[j] = s1[i];
			++j;
		}
	}
}

