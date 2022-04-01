#include <stdio.h>

/* 1.13.
	
*/

#define IN  1	/* in a word */
#define OUT 0	/* out of word */
#define MAX_WORD_LEN 100

main() {

	int i, j, c, state, wl, curr_hist_len, hist_max_val;
	int hist[MAX_WORD_LEN];
	
	wl = curr_hist_len = hist_max_val = 0;	
	state = OUT;
	for(i = 0; i <MAX_WORD_LEN; ++i)
		hist[i] = 0;

	while((c = getchar()) != EOF) {
		if(c == ' ' || c == '\n' || c == '\t') {
			if(state == IN && wl > 0) {
				if(wl > curr_hist_len)
					curr_hist_len = wl;
				++hist[wl-1];
				if(hist[wl-1] > hist_max_val)
					hist_max_val = hist[wl-1];
			}
			wl = 0;
			state = OUT;
			
		}
		else if(state == OUT)
			state = IN;

		if(state == IN) {
			++wl;
			/* printf("wl = %d\n", wl); */
		}
			
	}

	for(j = hist_max_val; j > 0; --j) {
		for(i = 0; i < curr_hist_len; ++i)
			if(hist[i] >= j)
				printf("* ");
			else
				printf("  ");
		
		putchar('\n');
	}
	
	for(i = 0; i < curr_hist_len; ++i)
		printf("%d ", i);
	putchar('\n');
	
}



/*
main() {
	int c, i, nwhite, nother;
	int ndigit[10];
	
	nwhite = nother = 0;
	for(i = 0; i < 10; ++i)
		ndigit[i] = 0;
	
	while((c = getchar()) != EOF)
		if(c >= '0' && c <= '9')
			++ndigit[c - '0'];
		else if(c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;

	printf("digits = ");
	for(i = 0; i < 10; ++i)
		printf("%d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
}
*/
