#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main() {
	char s[] = "Join the navy!";

	reverse(s);
	printf("%s\n", s);

	return 0;
}

void reverse(char s[]) {
	static int i = 0;
	char tmp;

	if(i <= (strlen(s)/2)) {
		tmp = s[i];
		s[i] = s[strlen(s) - i -1];
		s[strlen(s) - i -1] = tmp;

		i++;
		reverse(s);
	} else {
		i = 0;
	}
}