#include <stdio.h>

#define LOWER -20
#define UPPER 150
#define STEP 20

float cToF(float celsius);

int main() {
	float celsius;
	celsius = LOWER;

	printf("TEMPERATURE CONVERSION PROGRAM C TO F");

	while (celsius <= UPPER) {
		printf("%6.1f %3.0f\n", celsius, cToF(celsius));
		celsius = celsius + STEP;
	}

	return 0;
}

/* Converts Celsius to Farenheit */ 
float cToF(float celsius) {
	float fahr;
	fahr = (celsius*9.0/5.0) + 32.0;
	return fahr;
}