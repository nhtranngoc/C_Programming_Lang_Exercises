#include <stdio.h>
#define MAXCHAR 100

void strcat2(char *s, char *t);

int main() {
	char s1[MAXCHAR] = "Hello there, ";
	char s2[MAXCHAR] = "Obi-wan Kenobi. ";
	char s3[MAXCHAR] = "You're a bold one.";

	strcat2(s1 ,s2);
	strcat2(s1, s3);	

	printf("%s", s1);
	return 0;
}

void strcat2(char *s, char *t) {
	while(*++s);
	while(*s++ = *t++);
}