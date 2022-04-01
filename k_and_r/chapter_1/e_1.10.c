#include <stdio.h>

/* 1.10.
	Заменяет символы:
		табуляцию на \t
		backspace на \b
		обратную черту на \\
*/
main() {
	int c, replace;

	replace = 0;
	while((c = getchar()) != EOF) {
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
