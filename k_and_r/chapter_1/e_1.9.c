/* 
 * e_1.9.
 *
 * Status
 *	done
 *
 * Description
 *	Copy input to output, replacing each string of one or more blanks
 *	by a single blank	
 *
 * Note
 *	#1: by blank means ' ' (space).
 */
#include <stdio.h>

int main() 
{
	int i, c, cnt, cnt_sp;

	cnt = 0;
	cnt_sp = 0;
	while ((c = getchar()) != EOF) {
		++cnt;
		if (c == ' ')
			++cnt_sp;
		if (c != ' ') {
			if (c == '\n') {
				if (cnt-1 == cnt_sp)
					cnt_sp = 1;
				cnt = 0;
			}

			/* keep print blank if non-blank line */
			for(i = 0; i < cnt_sp; ++i)
				putchar('*');
			cnt_sp = 0;

			/* visual end of line */
			if(c == '\n') {
				putchar('\\'); 			}
			putchar(c);
		}		
			
	}
	return 0;
}
