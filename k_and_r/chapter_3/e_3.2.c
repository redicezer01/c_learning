/*
 * e_3.2.
 *
 * Status
 *	done
 *
 * Description
 *	Write a funtion escape(s, t) that converts characters like newline 
 *	and tab into visible escape sequences like \n and \t as it copies 
 *	the string t to s. Write a function for the other direction as well, 
 *	converting escape sequences into the real characters.
 */
#include <stdio.h>

void escape(char s[], char t[]);

int main()
{
	char s[100] = "";
	char t[100] = "some	str\nnewl\\nsecondline";
	escape(s, t);
	printf("%s", s);

	return 0;
}

void escape(char s[], char t[])
{
	char c;
	int i, j;
	i = 0, j = 0; 
	while ((c = t[i]) != '\0') {
		switch (c) {
		case '\t':
			s[j] = '\\';
			s[++j] = 't';
			break;
		case '\n':
			s[j] = '\\';
			s[++j] = 'n';
			break;
		case '\\':
			switch (t[i+1]) {
			case 'n':
				s[j] = '\n';
				++i;
				break;
			case 't':
				s[j] = '\t';	
				++i;
				break;
			}
			break;	
		default:
			s[j] = c;
			
		}
		++j;
		++i;
	}
}
