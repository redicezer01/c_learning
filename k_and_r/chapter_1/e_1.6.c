#include <stdio.h>

/* вывести значение getchar() != EOF 
	contrl + d - is EOF in Linux
	control + z - is EOF in Windows */
main() {
	printf("%d\n", getchar() != EOF);	
}
