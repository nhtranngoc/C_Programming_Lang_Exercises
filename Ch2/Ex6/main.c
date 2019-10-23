#include <stdio.h>

void printbits(size_t const size, void const * const ptr);

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);
unsigned int getbits(unsigned int x,int p, int n);

int main() {
	unsigned int b1 = 0b11101111;
	unsigned int b2 = 0b01010101;
	unsigned int b3 = setbits(b1,5,4,b2);

	printf("B1: ");
	printbits(1, &b1);
	printf("B2: ");
	printbits(1, &b2);
	printf("B3: ");
	printbits(1, &b3);
	return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
	unsigned int y_prime = (y >> n) << n; // Mask out part of y
	unsigned int x_prime = getbits(x,p,n);
	
	return x_prime | y_prime;
}

unsigned int getbits(unsigned x, int p, int n) {
	return (x >> (p+1-n)) & ~(~0 << n);
}


// Print binary, size is the number of bits
void printbits(size_t const size, void const * const ptr) {
	unsigned char *b = (unsigned char*) ptr;
	unsigned char byte;
	int i, j;

	for(i=size-1;i>=0;i--) {
		for(j=7;j>=0;j--) {
			byte = (b[i] >> j) & 1;
			if(j == 3) {
				printf(" ");
			}
			printf("%u", byte);
		}
	}
	puts("");
}