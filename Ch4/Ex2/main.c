#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main() {
	char s[] = "123.45e6";

	printf("%.10f", atof(s));

	return 0;
}

double atof(char s[]) {
	double val, power;
	int i, sign, expo;

	for(i = 0; isspace(s[i]); i++);

	sign = (s[i] == '-' ? -1 : 1);
	if(s[i] == '+' || s[i] == '-') {
		i++;
	}

	for(val = 0.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
	}

	if(s[i] == '.') {
		i++;
	}

	for(power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	val = sign * val / power;

	if(s[i] == 'e' || s[i] == 'E') {
		if(isdigit(s[i+1])) {
			sign = 1;
			expo = s[i+1] - '0';
		} else {
			sign = (s[i+1] == '-' ? -1 : 1);
			expo = s[i+2] - '0';
		}

		for(int j = 0; j < expo; j++) {
			val = (sign == -1) ? val / 10 : val * 10;
		}
	}

	return val;
}