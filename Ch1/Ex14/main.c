#include <stdio.h>

#define CHARACTER_MAX 128 //ASCII character range

int main() {
	int c;
	int freq[CHARACTER_MAX];

	for(int i = 0; i < CHARACTER_MAX; ++i) {
		freq[i] = 0;
	}

	while((c = getchar()) != EOF) {
		++freq[c];
	}

    for (int i = 0; i <= CHARACTER_MAX; ++i) {
        printf("%d ", i);
        for (int a = 0; a < freq[i]; ++a) {
            printf("*");
        }

        printf("\n");
    }

	return 0;
}