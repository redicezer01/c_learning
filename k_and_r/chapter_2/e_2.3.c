/*
 * 2.3.
 * htoi(s) converts a string of hexadecimal digits 
 * (conluding and optional 0x or 0X) into its equivalent integer value.
 *
 */

#include <stdio.h>
#include <ctype.h>

#define PREFIX 
int htoi(const char s[]);
int htod(char c);

int main()
{
	int dec;

	dec = 0;
	dec = htoi("0x1234AB");

	printf("%d\n", dec);

	return 0;
}

/*
 * htoi(s) converts a string of hexadecimal digits 
 * (conluding and optional 0x or 0X) into its equivalent integer value.
*/
int htoi(const char s[])
{
	char c;
	int i, n, d;
	i = n = 0;

	if (s[0]=='0' && (s[1]=='x' || s[1]=='X'))
		i = 2;
	
	for (i = i; isxdigit(c = s[i]); ++i) {
		if (!islower(c))
			c = tolower(c);

		d = htod(c);

		n = (n * 16) + d;
	}
	return n;
}

/*
 * htod converts hexadecimal char to integer value (0-15)
 */
int htod(char c)
{
	if (isdigit(c))
		return c - '0';
	else
		return c - 'a' + 10;
}
