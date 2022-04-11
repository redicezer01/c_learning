/* 
 * e_1.21.
 *
 * Status
 *	done
 *
 * Description
 * 	entab - replaces strings of blanks by minimum number
 * 	of tabs and blanks to space to the next tab stop.
 */
#include <stdio.h>

#define TABSTOP 8	/* tab size. */
#define LIMIT 1000	/* Max line length */

int getline(char line[], int lim);
int isblank(char s[]);

int main()
{
	char line[LIMIT];
	int len, i, nsp, ntabs;
	
	while ((len = getline(line, LIMIT)) > 0) {
		if ((nsp = isblank(line)) > 0) {
			ntabs = nsp / TABSTOP;
			nsp = nsp - (ntabs*TABSTOP);
			for (i = 0; i < ntabs; ++i)
				putchar('\t');
			for (i = 0; i <nsp; ++i)
				putchar('*');
			putchar('\n');
				
		} else {
			printf("%s", line);
		}
	}
	return 0;
}

/*
 * getline reads input by one char and collect to line array.
 * returns count of char readed til newline character '\n'.
 */
int getline(char line[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c=getchar()) !=EOF && c!='\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/*
 * isblank compares number of char and blanks in the string.
 * returns number of blanks if hole string consist of blanks
 * 	and 0 if string is not blank
 */
int isblank(char s[])
{
	int i, sp;
	sp = 0;
	for (i = 0; s[i] != '\0'; ++i)
		if (s[i] == ' ')
			++sp;
	if (s[i-1] == '\n')
		--i;	/* removing newline char from counting */
	if (i == sp)
		return sp;
	
	return 0;
}
