/* 1.19.
	reverse reverses its input a line at a time.
*/

/*
   TODO:
	1. revise and improve algorithm
*/

#include <stdio.h>

#define MAX   1000	/* Maximum line length. Limit for array length. */
#define TRUE  1
#define FALSE 0

int reverse(int s[]);
int isodd(int n);
int getline(int l[]);

int main() {
	int line[MAX];
	int i;
	
	/* getting lines. */
	while(getline(line) == TRUE) {
		if(reverse(line) == 0 ) {
			/* print reversed line. */	
			for(i=0; line[i]!='\0'; ++i)
				putchar(line[i]);
			putchar('\n');
		}
	}
	return 0;
}

/* getline split incoming character stream into lines. */
int getline(int l[]) {
	int c, i;

	for(i=0; (c=getchar()) != EOF; ++i) {
		if(c=='\n') {
			l[i] = '\0';
			return TRUE;
		}
		l[i] = c;
	}
	return FALSE;
}

/* reverse() reverses given string.
   return 1 if given string is empty. */
int reverse(int s[]) {
	int len, i, half, c;
	
	/* length of string */
	for(len = 0; s[len] != '\0'; ++len);

	/* empty string */
	if(len == 0)
		return 1;

	/* calculating middle of a string. */	
	if(isodd == FALSE) 
		--len;
	half = len/2;
	
	/* swaps opposite chars around the middle. */
	for(i=0; i<half; ++i) {
		c = s[i];
		s[i] = s[len-1-i];
		s[len-1-i] = c;
	}	
	
	return 0;	
}

/* isodd returns TRUE if given argument is odd */
int isodd(int n) {
	if ((n/2)*2 == n)
		return TRUE;
	return FALSE;
}


