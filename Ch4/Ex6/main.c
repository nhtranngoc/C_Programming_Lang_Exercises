#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "calc.h"

#define MAXOP 100
double var[MAX_VAR];
char tmp;

int main() {
	int type;
	double op2;
	char s[MAXOP];
	tmp = -1;

	for(int i = 0; i < MAX_VAR; ++i) {
		var[i] = 0;
	}

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
			case '^':
				op2 = pop();
				push(pow(pop(), op2));
				break;
			case VAR:
				printf("%s\n", s);

				if(strcmp(s, "sin") == 0) {
					printf("Sin\n");
					push(sin(pop()));
					break;	
				} else if(strcmp(s, "exp") == 0) {
					printf("EXP\n");
					push(exp(pop()));
					break;
				} else if(strlen(s) == 1) {
					tmp = s[0]; 
					printf("Set temp %c\n", tmp);
					break;
				} 

				printf("Error: Unknown command %s\n", s);

				break;
			case '=':
			// 	printf("%s\n", s);
			// 	if(!assign(s[0], pop())) {
			// 		printf("Error: Assignment failed");
			// 	};
				break;
			case '\n':
				if(tmp != -1) {
					if(s[0] == '=') {
						assign(tmp, pop());
					} else {
						retrieve(s[0]);
					}
				}

				tmp = -1;
				printf("\t%.8g\n", pop());
				clear();
				break;
			default:
				printf("Error: Unknown command %s\n", s);
				break;
		}
	}

	return 0;
}