#include <stdio.h>

/* TODO:
	1. revise and improve the algorithm
	2. Why printf can't printf buf (symbol array)
*/

#define TRUE  1
#define FALSE 0

/* 1.17
	prints all lines that are longer than 80 char.
*/
int main() {
	int c, i;
	int len; 	/* length of current line (not bigger than 80) */
	int buf[81];	/* buffer for lines that bigger than 80 */
	int printed;	/* indicates was buf printed or not */

	for(c = 0; c < 81; ++c)		/* clean buf */
		buf[c] = 0;		/* unnecessary */

	len = 0;	
	printed = FALSE;

	while((c = getchar()) != EOF) {
		if(len > 80) {
			if(printed == FALSE) {
				for(i = 0; buf[i] != '\0' && i < 81; ++i)
					putchar(buf[i]);
				printed = TRUE;
				buf[0] = '\0';
			}
			putchar(c);
		} else {
			buf[len] = c;
			++len;
			buf[len] = '\0';
		}
		if(c == '\n') {
			len = 0;
			printed = FALSE;
		}
		
	}
}
