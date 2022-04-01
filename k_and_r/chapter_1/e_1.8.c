#include <stdio.h>

/* подсчет кол-ва пробелов, табуляций, строк */
main() {
	int c, sp, tab, nl;

	sp = 0;		/* начальное значение кол-ва пробелов */
	tab = 0;	/* табуляций */
	nl = 0;		/* строк */

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
