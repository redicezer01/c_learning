/* 
 * e_1.8.
 *
 * Status
 *	done
 *
 * Description
 *	program counts blanks, tabs and newlines	
 */
#include <stdio.h>

main() {
	int c, sp, tab, nl;

	sp = 0;		/* spaces count */
	tab = 0;	/* tabs count */
	nl = 0;		/* newline count */

	while( (c = getchar()) != EOF) {
		if(c == ' ')
			++sp;
		if(c == '\t')
			++tab;
		if(c == '\n')
			++nl;
	}
	
	printf("spaces: %d, tabs: %d, newlines: %d\n", sp, tab, nl);

}
