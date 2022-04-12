/*
 * e_2.5.
 * 
 * Status
 *	done
 *
 * Description
 *	any(s1, s2) returns the first location in string s1
 *	where any characters from string s2 occurs
 */
#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
	char s1[] = "qwerty";
	char s2[] = "dhdhdhdthhy";
	printf("found at: %d\n", any(s1, s2));
	return 0;
}

int any(char s1[], char s2[])
{
	int pos = -1;
	int i, j;
	
	for (i = 0; s1[i] != '\0'; ++i)
		for (j = 0; s2[j] != '\0'; ++j)
			if (s1[i] == s2[j])
				return i;

	return pos;
}
