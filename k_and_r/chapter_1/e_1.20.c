/* 1.20.
	detab - replaces tabs in the input with the proper number blanks to space to the next tab stop.	
*/

/*
	TODO:
		1. revise and improve algorithm.
*/

#include <stdio.h>

#define TABSTOP 8	/* number of spaces in one tab stop */

int main() {
	int c, i;
	int nc;		/* chars count */ 
	int spaces;	/* count of spaces to print */
	int tabs;	/* count of tabs from begining of a line */

	for(nc = 0; (c=getchar()) != EOF; ++nc) {
		if(c == '\t') {
			/* calculate count of spaces to print */
			tabs = nc / TABSTOP;
			spaces = TABSTOP - (nc - tabs*TABSTOP);
			nc = nc + spaces - 1;

			for(i=0; i<spaces; ++i)
				putchar('*');
		} else {
			putchar(c);
		}			
		if(c == '\n')
			nc = -1;
	}		

}
