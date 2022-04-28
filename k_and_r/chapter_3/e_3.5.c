/*
 * e_3.5.
 *
 * Status
 *	done
 *
 * Description
 *	Write the function itob(n,s,b) that converts the integer n
 *	int a base b character representation in the string s. In 
 *	particular, itob(n,s,16) formats n as a hexadecimal integer 
 *	in s.
 */
#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itobl(int n, char s[], int b);

int main()
{
	char s[100];

	itobl(15, s, 16);
	printf("%s\n", s);
	itobl(20, s, 8);
	printf("%s\n", s);
	return (0);
}

void itobl(int n, char s[], int b)
{
	int i, sign;
	int r, c;
	char hex[] = {'A','B','C','D','E','F'};

	if ((sign = n) > 0)
		n = -n;
	i = 0;
	printf("%d\n", n);
	do {
		r = -(n % b);
		if (r > 9)
			c = hex[r-10];
		else
			c = r + '0';
		s[i++] = c;
	} while ((n /= b) < 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int i, j, c;
	int len = strlen(s);

	for (i = 0, j = len-1; i < len/2; ++i, --j)
		c = s[i], s[i] = s[j], s[j] = c;
}
