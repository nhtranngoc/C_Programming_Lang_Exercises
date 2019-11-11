#include <stdio.h>
#include <stdlib.h>

int strend(char *s, char *t);

int main() {
	char s1[] = "Join the navy";
	char s2[] = "navy";

	if(strend(s1,s3)){
		printf("Hooray!\n");	
	} else printf("Aww :(");

	return 0;
}

int strend(char *s, char *t) {
	while(*++s);

	int len = 0;
	while(*++t) {
		len++;
	}

	while(len-- > 0) {
		if(*s-- != *t--){
			return 0;
		}
	}

	return 1;
}