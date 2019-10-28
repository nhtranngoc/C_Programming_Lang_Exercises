#include <stdio.h> 

#define MAX_SIZE 100

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
	char s1[] = "BBBakldajskf	";
	char s2[MAX_SIZE];
	char s3[MAX_SIZE];

	escape(s2, s1);
	unescape(s3, s2);
	printf("%s\n", s2);
	printf("%s\n", s3);

	return 0;
}

void escape(char s[], char t[]) {
	int j = 0, i = 0;
	while(t[i] != '\0') {
		switch(t[i]) {
			case '\n':
				s[j] = '\\';
				j++;
				s[j] = 'n';
			break;
			case '\t':
				s[j] = '\\';
				j++;
				s[j] = 't';
			break;
			default:
				s[j] = t[i];
				j++;
			break;
		}
		++i;
	}
	s[i] = '\0';
	return;
}

void unescape(char s[], char t[]) {
	int i = 0, j = 0;
	while(t[i] != '\0') {
		++i;
		switch(t[i]) {
			case '\\':
			switch(t[i+j+1]) {
				case 'n':
					s[i] = '\n';
					i++;
					j++;
				break;
				case 't':
					s[i] = '\n';
					i++;
					j++;
				break;
				default:
				break;
			}
			break;
			default:
			s[j] = t[i+j];
			break;
		}
	}
	s[i] = '\0';
	return;
}