/*
 * 5.3.
 * Write a pointer version of the function strcat
 * that we showed in chapter 2: 
 * strcat(s, t) copies the string t to the end of s.
 *
 * Note: renamed strcat to strcatl
 * because of compiler error:
 * 	conflict in function name strcat and built-in strcat (string.h)
 */
#include <stdio.h>

void strcatl(char *s, char *t);

int main()
{
	int i;
	char s[10] = "1234";
	char t[3] = "56";

	printf("Before strcatl:\n");
	printf("\ts = %s\n\tt = %s\n", s, t);
	strcatl(s, t);
	printf("After strcatl:\n");
	printf("\ts = %s\n\tt = %s\n", s, t);

	return 0;
}

/* strcatl(s, t):
 * 	copies the string t to the end of s. 
 */
void strcatl(char *s, char *t)
{
	while (*s++ != '\0')
		;
	*s--;

	while (*s++ = *t++)
		;
}
