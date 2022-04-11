/* 
 * e_1.10.
 *
 * Status
 *	done
 *
 * Description
 *	Copy input to output, replacing each tab by \t, 
 *	each backspace by \b and each backslash by \\
 */
#include <stdio.h>

main()
{
	int c, replace;

	replace = 0;
	while ((c = getchar()) != EOF) {
		if(c == '\t') {
			putchar('\\');
			putchar('t');
			replace = 1;
		}
		if(c == '\b') {
			putchar('\\');
			putchar('b');
			replace = 1;
		}
		if(c == '\\') {
			putchar('\\');			
			putchar('\\');			
			replace = 1;
		}
		if(replace == 0)
			putchar(c);
		replace = 0;
		
	}
}
