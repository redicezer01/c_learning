/* 
 * e_1.11.
 *
 * Status
 *	done
 *
 * Description
 *	word count	
 */
#include <stdio.h>

#define IN  1	/* inside a word */
#define OUT 0	/* outside a word */

main() {

	int c, nl, nw, nc, state;
	
	state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != EOF) {
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if(state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}

/*
	Input that contains other excape sequances (other than \n and \t) 
	will lead to wrong result of word count.
*/
