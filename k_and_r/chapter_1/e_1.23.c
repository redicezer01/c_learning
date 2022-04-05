/*
 * 1.23.
 *
 */

/* 
 * TODO:
 *	revise and improve algorithm
 */

#include <stdio.h>

#define TRUE  1
#define FALSE 0

#define ALL    0
#define NON    1
#define CHECK  2

#define quote(c) (c == '\"')
#define copened(p,c) (p == '/' && c == '*')
#define cclosed(p,c) (p == '*' && c == '/')

int main()
{
	int c, pr;	/* current char */
	int st;		/* state = [ALL,NON, CHECK] */

	st = CHECK;
	pr = EOF; 
	
	while ((c=getchar()) != EOF) {
		if (quote(c) == TRUE) {
			if (st == ALL) {
				st = CHECK;
			} else {
				st = ALL;
			}
		} else if (copened(pr,c) && st == CHECK) {
			st = NON;
			pr = c = EOF;
		} else if (cclosed(pr,c) && st == NON) {
			st = CHECK;
			pr = c = EOF;
		}

		/* putchar */
		if (st == ALL) {
			putchar(pr);
		} else if (st == CHECK) {
			if (c != EOF)
				putchar(pr);
		}	
		if (c == '\n') {
			putchar(c);
			if (st == ALL)
				st = CHECK;
			c = EOF;	
		}
		pr = c;	
	}
}
