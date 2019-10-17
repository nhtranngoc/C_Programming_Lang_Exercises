#include <stdio.h>
#define TAB_SIZE 4	
#define MAX_BUFFER_SIZE 500

char bufferArray[MAX_BUFFER_SIZE]; 

int main() {
	int c, i, j;
	i = 0;
	while(1) {
		c = getchar();
		if (c == '\t') {
			for(j = i; j < TAB_SIZE; j++) {
				bufferArray[j] = ' ';
			}
			i = i + TAB_SIZE;
		}

		bufferArray[i] = c;
		i++;

		if (c == EOF) {
			break;
		}
	}

	printf("%s", bufferArray);

	return 0;
}