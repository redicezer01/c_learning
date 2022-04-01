#include <stdio.h>

#define LEN 256

/* 1.14.
*/
main() {
	int c, i, j;
	int hist[LEN];

	for(i = 0; i < LEN; ++i)
		hist[i] = 0;
	
	while((c = getchar()) != EOF)
		if(c != '\n' && c != ' ')
			++hist[c];

	printf("\n\n------------------------\n");
	printf("Histogram --------------\n");
	printf("------------------------\n\n");

	for(i = 0; i < LEN; ++i)
		if(hist[i] > 0) {
			printf("%c | ", i);
			for(j = 0; j <hist[i]; ++j)
				printf("* ");
			putchar('\n');

		}
	printf("\n------------------------\n");
}
