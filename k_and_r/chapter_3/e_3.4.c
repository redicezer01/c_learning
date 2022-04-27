/*
 * e_3.4.
 *
 * Status
 *	done
 *
 * Description
 *	In a two's complement number representation, our version
 *	of itoa does not handle the largest negative number,
 *	that is, the value of n equal to -(2 pow wordsize-1). Explain why not.
 *	Modify it to print that value correctly, regardless of machine 
 *	on wich it runs.	
 *
 *	#1. Because absolute value of a largest positie number smaller
 *	    than minimal negative numbers absolute value.
 *
 *	#2. Here is modified version of K&R books version of itoa
 *
 *	Note#1: in my version used char type of number just for 
 *	convience. You can change type int or any other integer type.
 */
#include <stdio.h>
#include <string.h>

void itoal(char n, char s[]);
void reverse(char s[]);

int main()
{
	char n = -128;
	char s[9];
	itoal(n, s);
	printf("%s\n", s);
	return (0);
}

void itoal(char n, char s[])
{
	char i, sign = -1;
	
	/* process only negative numbers */
	if ((sign = n) >= 0)
		n = -n;

	i = 0;
	do {
		/* abs */
		s[i++] = -(n % 10) + '0';
	} while ((n /= 10) < 0);	
	
	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}

/* orig atoi in book */
/*
void itoal(char n, char s[])
{
	char i, sign;

	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);	
	
	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	reverse(s);
}
*/

void reverse(char s[])
{
	int i, j, c;
	int len = strlen(s);
	printf("strlen: %d\n", len);

	for (i = 0, j = len-1; i < len/2; ++i, --j)
		c = s[i], s[i] = s[j], s[j] = c;	
}
