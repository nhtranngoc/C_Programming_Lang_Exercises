#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100

int main() {
	int type;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF) {
		prints();
		switch(type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0) {
					push(pop() / op2);
				} else {
					printf("Error: Divide by zero\n");
				}
				break;
			case '%':
				op2 = pop();
				push((int)pop() % (int)op2);
				break;
			case 's':
				push(sin(pop()));
				break;
			case 'e':
				push(exp(pop()));
				break;
			case '^':
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("Error: Unknown command %s\n", s);
				break;
		}
	}

	return 0;
}