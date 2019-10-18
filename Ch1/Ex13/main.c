#include <stdio.h>

#define OUT 0
#define IN 1
#define MAX_WORD 10

int main() {
	int c, state, wordLength, wordCount;
	int length[MAX_WORD];

	state = OUT;
	wordLength = 0;

	for (int i = 0; i< MAX_WORD; ++i) {
		length[i] = 0;	
	}

	while((c = getchar()) != EOF) {
		++wordLength;
		if (c == ' ' || c == '\n' || c == '\t') {
			--wordLength;
			state = OUT;
		}

		if (state == OUT) {
			if (wordLength != 0 && wordLength < MAX_WORD) {
				++length[wordLength];
			}
			state = IN;
			wordLength = 0;
		}
	}

    for (int i = 0; i <= MAX_WORD; ++i) {
        printf("%d ", i);
        for (int a = 0; a < length[i]; ++a) {
            printf("*");
        }

        printf("\n");
    }

	return 0;
}