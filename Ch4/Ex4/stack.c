#include <stdio.h>
#include "calc.h"
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
	if(sp < MAXVAL) {
		val[sp++] = f;
	} else {
		printf("Error: Stack full, can't push %g\n", f);
	}
}

double pop(void) {
	if(sp > 0) {
		return val[--sp];
	} else {
		printf("Error: Stack empty.\n");
		return 0.0;
	}
}

double head() {
	if(sp > 0) {
		return val[sp - 1];
	} else {
		printf("Error: Stack empty.\n");
		return 0.0;
	}
}

void duplicate() {
	push(head());
}

void swap() {
	if(sp >= 2) {
		double tmp = val[sp];
		val[sp] = val[sp-1];
		val[sp-1] = tmp;
	} else {
		printf("Error: Not enough elements to swap");
	}
}

void clear() {
	sp = 0;
}

void prints() {
	printf("Stack ");
	for(int i=0; i <= sp; ++i) {
		printf("%g ", val[i]);
	}
	puts("");
}