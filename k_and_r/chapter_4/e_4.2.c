/*
 * e_4.2.
 *
 * Status
 *	in progress
 *
 * Description
 *	Extend atof to handle scientific notation of the form:
 *		123.45e-6
 *	where a floating-point number may be followed be e or E
 *	and an optionally signed exponent.
 */
#include <stdio.h>
#include <ctype.h>


int main()
{
	float atof(char s[]);

	printf("%.9f\n", atof("123.456e-3"));
	return (0);
}

float atof(char s[])
{
	float val, power;
	int exp, expsign;
	int i, sign;

	for (i = 0; isspace(s[i]); ++i)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		++i;
	for (val = 0.0; isdigit(s[i]); ++i)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		++i;
	for (power = 1.0; isdigit(s[i]); ++i) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	/* handle scientific notation */
	if ((s[i] == 'e' || s[i] == 'E') && (s[i+1] == '-' || s[i+1] == '+')) {
		expsign = (s[i+1] == '-') ? -1 : 1;
		i += 2;
	}
	for (exp = 0; isdigit(s[i]); ++i) {
		exp = 10 * exp + (s[i] - '0');
	}
	while (exp--)
		if (expsign > 0)
			power /= 10;
		else
			power *= 10;
	/* END handle scientific notation */
	
	return sign * val / power;
}
