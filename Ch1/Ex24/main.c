#include <stdio.h>

#define MAX_ERRORS 1000
#define MAX_ROW 80
#define MAX_COL 80
#define INVALID -1
#define BRACK 1
#define BRACE 2
#define SQUOTE 3
#define DQUOTE 4
#define PAREN 5
#define SEMI 6

int addError();
void printErrors();
void errorMessage();
void removeError();

int errorRow[MAX_ROW];
int errorCol[MAX_COL];
int errorCode[MAX_ERRORS];	
int i = 0;
int parenCounter = 0, brackCounter = 0, braceCounter = 0, squoteCounter = 0, dquoteCounter = 0, semiCounter = 0;
int parenIndex = 0, brackIndex = 0, braceIndex = 0, squoteIndex = 0, dquoteIndex = 0;

int main() {
	char c, lastc = 0;
	int row = 1, col = 0;

	while((c = getchar()) != EOF) {
		++col;
		if(c == '\n') {
			++row;
			col = 0;
		}

		//Check for errors
		if(c == '{') {
			++braceCounter;
			braceIndex = addError(row, col, BRACE);
		} else if(c == '}' && braceCounter > 0) {
			--braceCounter;
			removeError(braceIndex);
		}

		if(c == '[') {
			++brackCounter;
			brackIndex = addError(row, col, BRACK);

		} else if(c == ']' && brackCounter > 0) {
			--brackCounter;
			removeError(brackIndex);
		}

		if(c == '(') {
			++parenCounter;
			parenIndex = addError(row, col, PAREN);
		} else if(c == ')' && parenCounter > 0) {
			--parenCounter;
			removeError(parenIndex);
		}

		if(c == '\'') {
			++squoteCounter;
			if((squoteCounter % 2) != 0) {
				squoteIndex = addError(row, col, SQUOTE);
			}  else removeError(squoteIndex);
		}

		if(c == '\"') {
			++dquoteCounter;
			if((dquoteCounter %2) != 0) {
				dquoteIndex = addError(row, col, DQUOTE);
			} else removeError(dquoteIndex);
		}

		if(c == '\n' && lastc != ';' && lastc != '{' && lastc != '>' && lastc != '\n') {
			++semiCounter;
			addError(row, col, SEMI);
		}
		lastc = c;
	}

	printErrors();

	return 0;
}

//Register the error into the system
int addError(int row, int col, int code) {
	errorRow[i] = row;
	errorCol[i] = col;
	errorCode[i] = code;
	int j = i;
	++i;

	return j;
}

//Does not remove errors, per se, but make index invalid so it wouldn't count
void removeError(int index) {
	errorCode[index] = INVALID; 
}

//Print errors if any
void printErrors() {
	for(int j = 0; j < MAX_ERRORS; ++j) {
		if(errorCode[j] == BRACE && braceCounter != 0) {
			errorMessage(errorRow[j], errorCol[j], "brace");
		}
		if(errorCode[j] == BRACK && brackCounter != 0) {
			errorMessage(errorRow[j], errorCol[j], "brack");
		}
		if(errorCode[j] == PAREN && parenCounter != 0) {
			errorMessage(errorRow[j], errorCol[j], "parenthesis");
		}
		if(errorCode[j] == SQUOTE) {
			errorMessage(errorRow[j], errorCol[j], "single quote");
		}
		if(errorCode[j] == DQUOTE) {
			errorMessage(errorRow[j], errorCode[j], "double quote");
		}
		if(errorCode[j] == SEMI) {
			errorMessage(errorRow[j], errorCol[j], "semicolon");
		}
	}
}

void errorMessage(int row, int col, char s[]) {
	printf("Missing %s at row %d, col %d\n", s, row, col);
}