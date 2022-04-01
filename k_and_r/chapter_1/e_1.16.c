#include <stdio.h>

int getline();

int main() {
	int len;	/* длина текущей строки */
	int max;	/* длина самой длинной строки */	

	max = 0;
	while((len = getline()) > 0) {
		if(len > max)
			max = len;
	}

	if(max > 0)
		printf("longest line length: %d\n", max);
	return 0;
}

int getline() {
	int i, c;
	
	for(i = 0; (c=getchar())!=EOF && c!='\n'; ++i)
		;

	return i;
}
