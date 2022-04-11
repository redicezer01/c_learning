/* 
 * e_1.18.
 *
 * Status
 *	done
 *
 * Description
 *	Removes trailing blanks and tabs each line of input,
 * 	and deletes entirely blanks lines.
 */
#include <stdio.h>

#define MAX 1000 /* maximum countof stored blanks */

int main() {
	int c, i;
	int nblank;	/* count of blanks in a row */
	int buf[MAX];	/* buf that stores blanks */

	while((c=getchar()) != EOF) {
		if(c==' ' || c=='\t') {
			buf[nblank] = c;	/* saving blanks */
			++nblank;
		} else {
			/* if blanks are in the middle of string, then print them. */
			if(c != '\n' && nblank > 0) {
				for(i=0; i<nblank; ++i)
					putchar(buf[i]);
			}
			nblank = 0;

			/* print newline symbol, just for clarity */
			if(c == '\n')
				printf("\\n");
			putchar(c);
			
		}
	}
}
