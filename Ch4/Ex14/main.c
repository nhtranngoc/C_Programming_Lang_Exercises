#include <stdio.h>

#define swap(t,x,y) do {x = x + y;y = x - y;x = x - y;} while(0)

int main() {
	int a,b;
	a = 80;
	b = 5;
	printf("Pre-swap:  a = %d, b = %d\n", a, b);
	swap(int,a,b);
	printf("Post-swap: a = %d, b = %d\n", a, b);

	return 0;
}
