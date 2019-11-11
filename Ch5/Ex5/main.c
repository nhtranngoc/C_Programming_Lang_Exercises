#include <stdio.h>

#define MAXCHAR 100

char *strncpy2(char *s, char *t, int n);
char *strncat2(char *s, char *t, int n);
int strncmp2(char *s, char *t, int n);

int main() {
	char s0[MAXCHAR] = "Ok ";
	char s1[MAXCHAR];
	char s2[MAXCHAR] = "boomer. This is unnecessary.";
	char s3[MAXCHAR] = "Ok boomer.";

	strncpy2(s1,s0,3);
	printf("%s\n", s1);
	strncat2(s1, s2,7);
	printf("%s\n", s1);

	if(strncmp2(s1,s3,9) == 0) {
		printf("It works!");
	} else printf("Eh.");

	return 0;
}

char *strncpy2(char *s, char *t, int n) {
	while(n-- > 0) {
		*s++ = *t++;
	}
}

char *strncat2(char *s, char *t, int n) {
	while(*++s);

	while(n-- > 0) {
		*s++ = *t++;
	}
	*s = '\0';
}

int strncmp2(char *s, char *t, int n) {
	while(n-- > 0) {
		if(*s++ == *t++) {
			if(*s == '\0') {
				return 0;
			}
		}

		return *s - *t;
	}
}