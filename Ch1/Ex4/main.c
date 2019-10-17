#include <stdio.h>

main() {
	float fahr, celsius;
	int lower, upper, step;

	lower = -20;
	upper = 150;
	step = 20; 

	celsius = lower;

	printf("TEMPERATURE CONVERSION PROGRAM C TO F")

	while (celsius <= upper) {
		fahr = (celsius*9.0/5.0) + 32.0;
		printf("%6.1f %3.0f\n", celsius, fahr);
		celsius = celsius + step;
	}

}