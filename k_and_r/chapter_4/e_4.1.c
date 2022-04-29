/*
 * e_4.1.
 *
 * Status
 *	done
 *
 * Description
 *	Write the function strrindex(s,t), which returns the position of the 
 *	rightmost occurence of t in s, or -1 if there is none.
 *
 *	Solution#1: simple, save i in found variable where t in s till the 
 *	end of s. At the end in found will be righmost index of occurence
 *	t in s.
 *
 * 	Solution#2: little bit harder. Same as leftmost occurence,
 *	except of iteration order (from the end ofr string searching).
 */
#include <stdio.h>
#include <string.h>

int  strrindex(char s[], char t[]);
int  strrindex2(char s[], char t[]);

int main()
{
	char s[] = "abcabcabc";
	char t[] = "abc";
	printf("t in s found at: %d\n", strrindex2(s, t));
	return (0);
}

int  strrindex(char s[], char t[])
{
	int found = -1;
	int i, j, k;
	for (i = 0; s[i] != '\0'; ++i) {
		for (j = i, k = 0; t[k]!='\0' && t[k]==s[j]; ++j, ++k)
			;
		if (k > 0 && t[k] == '\0')
			found = i;	
	}
	return found;
}

int  strrindex2(char s[], char t[])
{
	int i, j, k;
	int ls, lt;
	ls = strlen(s)-1, lt = strlen(t)-1;
	for (i = ls; i >= 0; --i) {
		for (j = i, k = lt; k >= 0 && t[k]==s[j]; --j, --k)
			;
		if (k == -1)
			return i-lt;
	}
	return -1;
}
