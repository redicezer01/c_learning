/* 
 * e_1.22.
 *
 * Status
 *	in progress
 *
 * Description
 * 	Fold log input line in to two or more shorter lines.
 */
#include <stdio.h>

#define N 60
#define TRUE 1
#define FALSE 0

int isblank(int c);


int main()
{
	int c, i;
	int buf[N];
	int end;	/* count of char in buf */
	int pos;	/* position of last blank symbol */

	end = pos = 0;
	while ((c = getchar()) != EOF) {
		if (end == N) {
			if (pos == 0)
				pos = end;
			for (i = 0; i < pos; ++i)
				putchar(buf[i]);
			int j, new_pos;	
			j = new_pos = 0;
			for (i = pos; i <= end; ++i) {
				buf[j] = buf[i];
				if (isblank(buf[i]) == TRUE) {
					new_pos = j;
				}		
				++j;
			}
			end = j-1;
			pos = new_pos;
			putchar('\n');
		} else {
			if (c == '\n') {
				for (i = 0; i < end; ++i)
					putchar(buf[i]);
				putchar(c);
				end = pos = 0;
			} else {
				buf[end] = c;
				++end;
			}
			if (isblank(c) == TRUE) {
				pos = end;
			}		
		}	
	}
	return 0;
}

int isblank(int c)
{
	return c == ' ' || c == '\t';
}
