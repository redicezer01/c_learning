/*
 * e_2.10.
 * 
 * Status
 *	done
 *
 * Description
 *	Rewrite the function lower (section 2.7, page 43), wich converts upper case letters
 *	to lower case, with a conditional expression instead of if-else.
 */
#include <stdio.h>

int lower(int c);

int main()
{
	printf("%c\n", lower('D'));
	return (0);
}

int lower(int c)
{
	return ('A' <= c && c <= 'Z') ? c + 'a' - 'A' : c;
}
