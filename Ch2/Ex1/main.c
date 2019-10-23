#include <stdio.h>
#include <limits.h>

int main() {
	printf("Unsigned char from 0 to %d\n", UCHAR_MAX);
	printf("Unsigned short from 0 to %d\n", USHRT_MAX);
	printf("Unsigned int from 0 to %u\n", UINT_MAX);
	printf("Unsigned long from 0 to %lu\n", ULONG_MAX);

	printf("Signed char from %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Signed short from %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("Signed int from %d to %d\n", INT_MIN, INT_MAX);
	printf("Signed long from %ld to %ld\n", LONG_MIN, LONG_MAX);

	return 0;
}