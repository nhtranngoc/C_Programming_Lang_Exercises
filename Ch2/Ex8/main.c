#include <stdio.h>

int rightrot(unsigned int x, int n);
void printbits(size_t const size, void const * const ptr);

int main() {
	unsigned int b1 = 0b00011000;
	unsigned int b2 = rightrot(b1,4);

	printbits(sizeof b2,&b2);

	return 0;
}

int rightrot(unsigned int x, int n) {
	while(n-- > 0) {
		if((x&1) == 1) { //If first bit is even
			x = (x >> 1) | ~(~0U >> 1); ?//
		} else { //First bit is odd
			x = (x >> 1); // Shift x to the right once
		}
	}
	return x;
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