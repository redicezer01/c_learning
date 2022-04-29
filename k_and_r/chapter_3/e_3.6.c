/*
 * e_3.6.
 *
 * Status
 *	done
 *
 * Description
 *	Write a version of itoa that accpets three arguments instead of two.
 *	The third argument is a minimun field width; the converted number must
 *	be padded with blanks on the left if necessary to make it wide enough.
 */
#include <stdio.h>
#include <string.h>

void itoal(int n, char s[], int w);
void reverse(char s[]);

int main()
{
	char s[100];
	
	printf("-----\n");	
	itoal(123454, s,5);
	printf("%s\n", s);	

	return (0);
}

void itoal(int n, char s[], int w)
{
	int i, sign;
	if ((sign = n) > 0)
		n = -n;	

	/* converting */
	i = 0;
	do {
		s[i++] = -(n % 10) + '0';
	} while ((n /= 10) < 0);

	if (sign < 0)
		s[i++] = '-';

	/* padding with blanks */
	while (i < w)
		s[i++] = ' ';

	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int i, j, len, c;
	len = strlen(s);
	for (i = 0, j = len-1; i < (len/2); ++i, --j)
		c = s[i], s[i] = s[j], s[j] = c;
}
