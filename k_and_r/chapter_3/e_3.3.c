/*
 * e_3.3.
 *
 * Status
 *	done
 *
 * Description
 *	Write a function expand(s1, s2) that expands shorthand notations
 *	like a-z in the string s1 into the equivalent complete list abc...xyz
 *	in s2. Allow for letter of either case and digits, and be prepared
 *	to hadle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading
 *	or trailing - is taken literally.
 */
#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main()
{
	char s1[100] = "asd a-z df-0-9-dsf dfs ";
	char s2[1000];
	char *ptrs;
	expand(s1, s2);
	printf("%s\n", s1);
	printf("%s\n", s2);
	return 0;
}

void expand(char s1[], char s2[])
{
	int i, j, k;
	int s1len = strlen(s1);
	enum expand {NO, LABC, UABC, DIGIT};
	enum expand exp = NO;	
	
	for (i = 0, k = 0; i < s1len; ++i) {
		char from, to;
		if (i+2 <= s1len)
			switch(s1[i]) {
			case 'a':
				if (s1[i+1] == '-' && s1[i+2] == 'z') {
					exp = LABC;
					from = 'a', to = 'z';
					i += 2;
				}
				break;					
			case 'A':
				if (s1[i+1] == '-' && s1[i+2] == 'Z') {
					exp = UABC;
					from = 'A', to = 'Z';
					i += 2;
				}
				break;					
			case '0':
				if (s1[i+1] == '-' && s1[i+2] == '9') {
					exp = DIGIT;
					from = '0', to = '9';
					i += 2;
				}
				break;					
			}
		if (exp != NO)
			for (j = from; j <= to; ++j)
				s2[k++] = j;
		else
			s2[k++] = s1[i];
				
		exp = NO;
	}
}
