#include <stdio.h>

int bitcount(unsigned x);

int main() {
	unsigned int b1 = 01110010;

	int count = bitcount(b1);
	printf("%d", count);

	return 0;
}

int bitcount(unsigned x) {
	int i = 0;

	while(x) {
		x &= (x-1);
		++i;
	}

	return i;
}