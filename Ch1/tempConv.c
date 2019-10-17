// Exercise 1-4, 1-15
// Print Ceslius to Fahrenheit table

#include <stdio.h>

float celsToFahr (float cels);

int main() {
	float celsius, fahr;
	int lower, upper , step; 
	lower = 0;
	upper = 150;
	step = 10;

	celsius = lower;
	printf ("Temperature Conversion \n");
	while (celsius <= upper) {
		fahr = celsToFahr(celsius);
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}

	return 0;
}

float celsToFahr (float cels) {
	return ((cels * 9.0/5.0) + 32.0);
}