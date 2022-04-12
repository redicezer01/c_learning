/*
 * e_2.4.
 * 
 * Status
 *	done
 *
 * Description
 * 	Write an alternate version of squeeze(s1, s2) that
 * 	deletes characters in s1 matches any character in the string s2.
 */
#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
	char s1[] = "qwerty";
	char s2[] = "wt";
	squeeze(s1, s2);
	return 0;
}

void squeeze(char s1[], char s2[])
{
	int i, j, k;
	for (i = j = 0; s1[i] != '\0'; i++) {
		for (k = 0; (s2[k] != s1[i]) && (s2[k] != '\0'); k++)
			;
		if (s2[k] == '\0') {
			s1[j++] = s1[i];
		}
	}
	s1[j] = '\0';
	printf("%s\n", s1);
}

/*
 * original squeeze
 */
/*
void squeeze(char s[], char c)
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
	printf("%s\n", s);
}
*/
