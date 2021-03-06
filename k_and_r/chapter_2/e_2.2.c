/*
 * e_2.2.
 * 
 * Status
 *	done
 *
 * Description
 *	Write cycle without using && or ||
 */
#include <stdio.h>

#define LIM 8

int main()
{
	int i = 0, lim = LIM;
	char c;
	char s[LIM];
	
	/* getline */
	while ((c = getchar()) != EOF) {
		if (c != '\n')
			if (i < lim-1) {
				s[i] = c;
				++i;
			}
	}
	s[i] = '\0';
	printf("Output:\n%s\n", s);
	return 0;
}
